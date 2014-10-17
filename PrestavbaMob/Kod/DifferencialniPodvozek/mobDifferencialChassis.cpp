#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <chrono>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <pthread.h>
#include <fcntl.h>


#include "mobDifferencialChassis.h"
#include "../../../obecne/basic.h"

const unsigned int BUFFER_SIZE = 10;

MobDifferentialChassis::MobDifferentialChassis(DiffChassisParam &diffChassisParam) : BasicDifferentialChassis(diffChassisParam) {
	end_ = false;
	sendMotorPower(motorsPower(0, 0));

	loopPidThread_ = std::move(std::thread(&MobDifferentialChassis::updateEncoders,this,5));
	// set thread higher priority and FIFO order
	struct sched_param param;
	param.__sched_priority = 90;
	pthread_setschedparam(loopPidThread_.native_handle(),SCHED_FIFO,&param);
	
	if(mlockall(MCL_CURRENT)){
		fprintf(stderr,"Warning: Failed to lock memory \n");
	}

	//pthread_create(&updateEncodersThreadHandler, NULL, &updateEncodersThread, (void*) this);
}

DistanceWheels MobDifferentialChassis::computeDistance(Encoders distance) {
	DistanceWheels distanceInMeters;
	distanceInMeters.left = distance.left * diffChassisParam_.metersPerTick;
	distanceInMeters.right = distance.right * diffChassisParam_.metersPerTick;
	return distanceInMeters;
}

VelocityWheels MobDifferentialChassis::computeSpeed(DistanceWheels distance, double time) {
	VelocityWheels speed;
	speed.left = distance.left / time;
	speed.right = distance.right / time;

	return speed;
}

void MobDifferentialChassis::changeRobotState(DistanceWheels change) {
	double angleChange = (change.right - change.left) / diffChassisParam_.wheelbase;
	double distanceChange = (change.right + change.left) / 2.0;

	std::lock_guard<std::mutex> lock(stateMutex_);
	wheelsDistance_.left += change.left;
	wheelsDistance_.right += change.right;

	robotState_.x += distanceChange * cos(robotState_.theta + (angleChange / 2.0f));
	robotState_.y += distanceChange * sin(robotState_.theta + (angleChange / 2.0f));
	robotState_.theta += angleChange;
}

Encoders MobDifferentialChassis::getChangeOfEncoders() {
	return diffChassisParam_.encoder->getChangeOfEncoders();
}

int MobDifferentialChassis::sendMotorPower(struct motorsPower speedMotors) {
	return diffChassisParam_.driver->setMotorsPower(speedMotors);
}

int MobDifferentialChassis::PIRegulator(const double actualSpeed,const double desireSpeed, PIValue &PIParam) {
	double speedDifference = desireSpeed - actualSpeed;
	PIParam.ISum += speedDifference;

	int speed = PIParam.P * speedDifference + PIParam.I * PIParam.ISum;

	// set in boundaries
	return rob_fce::valueInRange<int>(speed, diffChassisParam_.driver->getMaxPower());
}

void MobDifferentialChassis::updateEncoders(const int period) {
	timeval timer[2];
	//printf("Sleep time: %i \n\r", This->encodersAcquireTime);

	long int lastMicroTime = 1;
	while(!end_.load()){
		gettimeofday(&timer[0], NULL);
		long int microStart = (timer[0].tv_sec * 1000000) + (timer[0].tv_usec);

		// Get encoders and compute distance
		Encoders differenceEncoders = getChangeOfEncoders();

		// Compute actual speed and use PID
		double time = (microStart - lastMicroTime) / 1000000.0f; // time in sec
		DistanceWheels distance = computeDistance(differenceEncoders);
		VelocityWheels actualSpeed = computeSpeed(distance, time);
		changeRobotState(distance);
		//printf("Actual speed left: %f  right: %f \n\r", actualSpeed.left, actualSpeed.right);
		
		speedMutex_.lock();
		wheelsSpeed_ = actualSpeed;
		VelocityWheels copyDesSpeed = wheelsDesireSpeed_;
		speedMutex_.unlock();
		
		motorsPower valueMotors;
		valueMotors.left = PIRegulator(actualSpeed.left, copyDesSpeed.left, diffChassisParam_.pidLeft);
		valueMotors.right = PIRegulator(actualSpeed.right, copyDesSpeed.right, diffChassisParam_.pidRight);
		//printf("Desire speed left: %f right: %f \n\r", This->desireSpeed.left, This->desireSpeed.right);
		
		//printf("Send motor speed left: %i right: %i \n\r", valueMotors.left, valueMotors.right);		

		sendMotorPower(valueMotors);

		gettimeofday(&timer[1], NULL);
		long int microStop = (timer[1].tv_sec * 1000000) + (timer[1].tv_usec);
		long int sleepMicro = period * 1000 - (microStop - microStart);
		lastMicroTime = microStart;

		//printf("Usleep time: %li \n\r", sleepMicro);
		std::this_thread::sleep_for(std::chrono::microseconds(sleepMicro));
	}
}

void MobDifferentialChassis::stop(bool slow) {

	if(slow){
		do{
			VelocityWheels desire;
			if(wheelsSpeed_.left > 0){
				desire.left = rob_fce::valueInRange<double>(wheelsSpeed_.left - STOP_SPEED, 0.0 , wheelsSpeed_.left);
			}else{
				desire.left = rob_fce::valueInRange<double>(wheelsSpeed_.left + STOP_SPEED, wheelsSpeed_.left, 0.0);
			}

			if(wheelsSpeed_.right > 0){
				desire.right = rob_fce::valueInRange<double>(wheelsSpeed_.right - STOP_SPEED, 0.0 , wheelsSpeed_.right);
			}else{
				desire.right = rob_fce::valueInRange<double>(wheelsSpeed_.right + STOP_SPEED, wheelsSpeed_.right, 0.0);
			}

			setVelocity(desire);
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}while(std::abs(wheelsSpeed_.left) > 1e-5 ||  std::abs(wheelsSpeed_.right) > 1e-5);
	}else{
		setVelocity(VelocityWheels(0, 0));
		diffChassisParam_.driver->stop();
	}

	diffChassisParam_.pidLeft.ISum = 0;
	diffChassisParam_.pidRight.ISum = 0;
}

void MobDifferentialChassis::setVelocity(const VelocityWheels speed) {
	VelocityWheels safeSpeed;
	safeSpeed.left = rob_fce::valueInRange(speed.left, diffChassisParam_.maxVelocity);
	safeSpeed.right = rob_fce::valueInRange(speed.right, diffChassisParam_.maxVelocity);
	
	std::lock_guard<std::mutex> lock(speedMutex_);
	wheelsDesireSpeed_ = safeSpeed;
}

void MobDifferentialChassis::setVelocity(const double distance, const double angle){
	VelocityWheels velocity;
	if(std::abs(angle) < EPSILON){
		velocity.left = diffChassisParam_.maxVelocity;
		velocity.right = diffChassisParam_.maxVelocity;
	}else{
		double radius = std::abs(distance / angle);
		double ratio = (radius - diffChassisParam_.wheelbase / 2.0) / (radius + diffChassisParam_.wheelbase / 2.0);
		if(angle >= 0){
			velocity.left = diffChassisParam_.maxVelocity*ratio;
			velocity.right = diffChassisParam_.maxVelocity;
		}else if(angle < 0){
			velocity.left = diffChassisParam_.maxVelocity;
			velocity.right = diffChassisParam_.maxVelocity*ratio;
		}
	}

	if(distance < EPSILON){
		velocity.left = -velocity.left;
		velocity.right = -velocity.right;
	}

	setVelocity(velocity);
}

State MobDifferentialChassis::getState() {
	std::lock_guard<std::mutex> lock(stateMutex_);
	return robotState_;
}

DistanceWheels MobDifferentialChassis::getDistanceWheels() {
	std::lock_guard<std::mutex> lock(stateMutex_);
	return wheelsDistance_;
}

VelocityWheels MobDifferentialChassis::getVelocityWheels(){
	std::lock_guard<std::mutex> lock(speedMutex_);
	return wheelsSpeed_;
}

MobDifferentialChassis::~MobDifferentialChassis(){
	end_.store(true);
	loopPidThread_.join();
}
