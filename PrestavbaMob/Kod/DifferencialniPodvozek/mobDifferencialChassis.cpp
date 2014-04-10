#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <chrono>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <pthread.h>
#include <fcntl.h>


#include "mobDifferencialChassis.h"
#include "../../../obecne/basic.h"

const unsigned int BUFFER_SIZE = 10;

MobDifferentialChassis::MobDifferentialChassis(const DiffChassisParam diffChassisParam) : BasicDifferentialChassis(diffChassisParam) {
	end_.store(false);
	metersPerTick_ = (2 * M_PI * diffChassisParam.wheelRadius) / (float) diffChassisParam.wheelTics;

	sendMotorPower(motorsPower(0, 0));

	// Set PI regulator parameters for left wheel
	PIParamLeft_.P = 200; // 740 oscillate value 
	PIParamLeft_.I = 12;
	
	// Set PI regulator parameters for right wheel
	PIParamRight_.P = 200; // 740 oscillate value 
	PIParamRight_.I = 12;

	loopPidThread_ = std::move(std::thread(&MobDifferentialChassis::updateEncoders,this,5));
	// set thread higher priority and FIFO order
	struct sched_param param;
	param.__sched_priority = 90;
	pthread_setschedparam(loopPidThread_.native_handle(),SCHED_FIFO,&param);
	
	//pthread_create(&updateEncodersThreadHandler, NULL, &updateEncodersThread, (void*) this);
}

WheelsDistance MobDifferentialChassis::computeDistance(Encoders distance) {
	WheelsDistance distanceInMeters;
	distanceInMeters.left = distance.left * metersPerTick_;
	distanceInMeters.right = distance.right * metersPerTick_;

	return distanceInMeters;
}

WheelsSpeed MobDifferentialChassis::computeSpeed(WheelsDistance distance, float time) {
	WheelsSpeed speed;
	speed.left = distance.left / time;
	speed.right = distance.right / time;

	return speed;
}

void MobDifferentialChassis::changeRobotState(WheelsDistance change) {
	double angleChange = (change.right - change.left) / diffChassisParam_.wheelbase;
	double distanceChange = (change.right + change.left) / 2;

	stateMutex_.lock();
	wheelsDistance_.left += change.left;
	wheelsDistance_.right += change.right;

	robotState_.position.x += distanceChange * cos(robotState_.angle + (angleChange / 2.0f));
	robotState_.position.y += distanceChange * sin(robotState_.angle + (angleChange / 2.0f));
	robotState_.angle += angleChange;
	stateMutex_.unlock();
}

Encoders MobDifferentialChassis::getChangeOfEncoders() {
	return diffChassisParam_.encoder->getChangeOfEncoders();
}

int MobDifferentialChassis::sendMotorPower(struct motorsPower speedMotors) {
	return diffChassisParam_.driver->setMotorsPower(speedMotors);
}

int MobDifferentialChassis::PIRegulator(const float actualSpeed,const float desireSpeed, PIValue &PIParam) {
	float speedDifference = desireSpeed - actualSpeed;
	PIParam.ISum += speedDifference;

	int speed = PIParam.P * speedDifference + PIParam.I * PIParam.ISum;

	// set in boundaries
	return basic_robotic_fce::valueInRange<int>(speed, diffChassisParam_.driver->getMaxPower());
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
		float time = (microStart - lastMicroTime) / 1000000.0f; // time in sec
		WheelsDistance distance = computeDistance(differenceEncoders);
		WheelsSpeed actualSpeed = computeSpeed(distance, time);
		changeRobotState(distance);
		//printf("Actual speed left: %f  right: %f \n\r", actualSpeed.left, actualSpeed.right);
		
		speedMutex_.lock();
		wheelsSpeed_ = actualSpeed;
		WheelsSpeed copyDesSpeed = wheelsDesireSpeed_;
		speedMutex_.unlock();
		
		motorsPower valueMotors;
		valueMotors.left = PIRegulator(actualSpeed.left, copyDesSpeed.left, PIParamLeft_);
		valueMotors.right = PIRegulator(actualSpeed.right, copyDesSpeed.right, PIParamRight_);
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
			WheelsSpeed desire;
			if(wheelsSpeed_.left > 0){
				desire.left = basic_robotic_fce::valueInRange<float>(wheelsSpeed_.left - 0.1, 0.0 , wheelsSpeed_.left);
			}else{
				desire.left = basic_robotic_fce::valueInRange<float>(wheelsSpeed_.left + 0.1, wheelsSpeed_.left, 0.0);
			}

			if(wheelsSpeed_.right > 0){
				desire.right = basic_robotic_fce::valueInRange<float>(wheelsSpeed_.right - 0.1, 0.0 , wheelsSpeed_.right);
			}else{
				desire.right = basic_robotic_fce::valueInRange<float>(wheelsSpeed_.right + 0.1, wheelsSpeed_.right, 0.0);
			}

			setSpeed(desire);
			std::this_thread::sleep_for(std::chrono::milliseconds(5));
		}while(abs(wheelsSpeed_.left) < 0.001 &&  abs(wheelsSpeed_.right) < 0.001);
	}else{
		setSpeed(WheelsSpeed(0, 0));
		diffChassisParam_.driver->stop();
	}

	PIParamLeft_.ISum = 0;
	PIParamRight_.ISum = 0;
}

void MobDifferentialChassis::setSpeed(const WheelsSpeed speed) {
	WheelsSpeed safeSpeed;
	safeSpeed.left = basic_robotic_fce::valueInRange(speed.left, diffChassisParam_.maxSpeed);
	safeSpeed.right = basic_robotic_fce::valueInRange(speed.right, diffChassisParam_.maxSpeed);
	
	std::lock_guard<std::mutex> lock(speedMutex_);
	wheelsDesireSpeed_ = safeSpeed;
}

State MobDifferentialChassis::getState() {
	std::lock_guard<std::mutex> lock(stateMutex_);
	return robotState_;
}

WheelsDistance MobDifferentialChassis::getWheelDistance() {
	std::lock_guard<std::mutex> lock(stateMutex_);
	return wheelsDistance_;
}

WheelsSpeed MobDifferentialChassis::getSpeed(){
	std::lock_guard<std::mutex> lock(speedMutex_);
	return wheelsSpeed_;
}

MobDifferentialChassis::~MobDifferentialChassis(){
	end_.store(true);
	loopPidThread_.join();
}
