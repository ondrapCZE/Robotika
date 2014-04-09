#include <stdio.h>
#include <stdlib.h>
#include <cmath>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <pthread.h>
#include <fcntl.h>
#include <mutex>
#include <iostream>

#include "mobDifferencialChassis.h"
#include "../../../obecne/basic.h"

const unsigned int BUFFER_SIZE = 10;

MobDifferentialChassis::MobDifferentialChassis(const DiffChassisParam diffChassisParam) : BasicDifferentialChassis(diffChassisParam) {
	end.store(false);
	metersPerTick = (2 * M_PI * diffChassisParam.wheelRadius) / (float) diffChassisParam.wheelTics;

	sendMotorPower(motorsPower(0, 0));

	// Set PI regulator parameters for left wheel
	PIParamLeft.P = 200; // 740 oscillate value 
	PIParamLeft.I = 12;
	
	// Set PI regulator parameters for right wheel
	PIParamRight.P = 200; // 740 oscillate value 
	PIParamRight.I = 12;

	loopPidThread = std::move(std::thread(&MobDifferentialChassis::updateEncoders,this,5));
	// set thread higher priority and FIFO order
	struct sched_param param;
	param.__sched_priority = 90;
	pthread_setschedparam(loopPidThread.native_handle(),SCHED_FIFO,&param);
	
	//pthread_create(&updateEncodersThreadHandler, NULL, &updateEncodersThread, (void*) this);
}

WheelsDistance MobDifferentialChassis::computeDistance(Encoders distance) {
	WheelsDistance distanceInMeters;
	distanceInMeters.left = distance.left * metersPerTick;
	distanceInMeters.right = distance.right * metersPerTick;

	return distanceInMeters;
}

WheelsSpeed MobDifferentialChassis::computeSpeed(WheelsDistance distance, float time) {
	WheelsSpeed speed;
	speed.left = distance.left / time;
	speed.right = distance.right / time;

	return speed;
}

void MobDifferentialChassis::changeRobotState(WheelsDistance change) {
	double angleChange = (change.right - change.left) / diffChassisParam.wheelbase;
	double distanceChange = (change.right + change.left) / 2;

	stateMutex.lock();
	wheelDistance.left += change.left;
	wheelDistance.right += change.right;

	robotState.position.x += distanceChange * cos(robotState.angle + (angleChange / 2.0f));
	robotState.position.y += distanceChange * sin(robotState.angle + (angleChange / 2.0f));
	robotState.angle += angleChange;
	stateMutex.unlock();
}

Encoders MobDifferentialChassis::getChangeOfEncoders() {
	return diffChassisParam.encoder->getChangeOfEncoders();
}

int MobDifferentialChassis::sendMotorPower(struct motorsPower speedMotors) {
	return diffChassisParam.driver->setMotorsPower(speedMotors);
}

int MobDifferentialChassis::PIRegulator(const float actualSpeed,const float desireSpeed, PIValue &PIParam) {
	float speedDifference = desireSpeed - actualSpeed;
	PIParam.ISum += speedDifference;

	int speed = PIParam.P * speedDifference + PIParam.I * PIParam.ISum;

	// set in boundaries
	return basic_robotic_fce::valueInRange<int>(speed, diffChassisParam.driver->getMaxPower());
}

void MobDifferentialChassis::updateEncoders(const int period) {
	timeval timer[2];
	//printf("Sleep time: %i \n\r", This->encodersAcquireTime);

	long int lastMicroTime = 1;
	while(!end.load()){
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
		
		speedMutex.lock();
		speed = actualSpeed;
		WheelsSpeed copyDesSpeed = desireSpeed;
		speedMutex.unlock();
		
		motorsPower valueMotors;
		valueMotors.left = PIRegulator(actualSpeed.left, copyDesSpeed.left, PIParamLeft);
		valueMotors.right = PIRegulator(actualSpeed.right, copyDesSpeed.right, PIParamRight);
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

void MobDifferentialChassis::stop() {
	PIParamLeft.ISum = 0;
	PIParamRight.ISum = 0;
	setSpeed(WheelsSpeed(0, 0));
	diffChassisParam.driver->stop();
}

void MobDifferentialChassis::setSpeed(const WheelsSpeed speed) {
	WheelsSpeed safeSpeed;
	safeSpeed.left = basic_robotic_fce::valueInRange(speed.left, diffChassisParam.maxSpeed);
	safeSpeed.right = basic_robotic_fce::valueInRange(speed.right, diffChassisParam.maxSpeed);
	
	std::lock_guard<std::mutex> lock(speedMutex);
	desireSpeed = safeSpeed;
}

State MobDifferentialChassis::getState() {
	std::lock_guard<std::mutex> lock(stateMutex);
	return robotState;
}

WheelsDistance MobDifferentialChassis::getWheelDistance() {
	std::lock_guard<std::mutex> lock(stateMutex);
	return wheelDistance;
}

WheelsSpeed MobDifferentialChassis::getSpeed(){
	std::lock_guard<std::mutex> lock(speedMutex);
	return speed;
}

MobDifferentialChassis::~MobDifferentialChassis(){
	end.store(true);
	loopPidThread.join();
}
