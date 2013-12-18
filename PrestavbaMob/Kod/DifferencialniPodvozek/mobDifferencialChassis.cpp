#include <stdio.h>
#include <stdlib.h>
#include <cmath>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <fcntl.h>
#include <c++/4.6/mutex>
#include <iostream>

#include "mobDifferencialChassis.h"
#include "../../../obecne/basic.h"

const unsigned int BUFFER_SIZE = 10;

MobDifferencialChassis::MobDifferencialChassis(const DiffChassisParam diffChassisParam) : BasicDifferencialChassis(diffChassisParam) {
	end = false;
	metersPerTick = (2 * M_PI * diffChassisParam.wheelRadius) / (float) diffChassisParam.wheelTics;

	sendMotorPower(motorsPower(0, 0));

	// Set PIRegulator
	PIRegulatorValue.P = 200; // 740 oscillate value 
	PIRegulatorValue.I = 12;

	//encodersAcquireTime = 10; // every x ms
	loopPidThread = std::move(std::thread(&MobDifferencialChassis::updateEncoders,this,10));
	//pthread_create(&updateEncodersThreadHandler, NULL, &updateEncodersThread, (void*) this);
}

WheelsDistance MobDifferencialChassis::computeDistance(Encoders distance) {
	WheelsDistance distanceInMeters;
	distanceInMeters.left = distance.left * metersPerTick;
	distanceInMeters.right = distance.right * metersPerTick;

	return distanceInMeters;
}

WheelsSpeed MobDifferencialChassis::computeSpeed(WheelsDistance distance, float time) {
	WheelsSpeed speed;
	speed.left = distance.left / time;
	speed.right = distance.right / time;

	return speed;
}

void MobDifferencialChassis::changeRobotState(WheelsDistance change) {
	double angleChange = (change.right - change.left) / diffChassisParam.wheelbase;
	double distanceChange = (change.right + change.left) / 2;

	stateMutex.lock();
	wheelDistance.left += change.left;
	wheelDistance.right += change.right;

	robotState.x += distanceChange * cos(robotState.angle + (angleChange / 2.0f));
	robotState.y += distanceChange * sin(robotState.angle + (angleChange / 2.0f));
	robotState.angle += angleChange;
	stateMutex.unlock();
}

Encoders MobDifferencialChassis::getChangeOfEncoders() {
	return diffChassisParam.encoder->getChangeOfEncoders();
}

int MobDifferencialChassis::sendMotorPower(struct motorsPower speedMotors) {
	return diffChassisParam.driver->setMotorsPower(speedMotors);
}

motorsPower MobDifferencialChassis::PIRegulator(WheelsSpeed actualSpeed, WheelsSpeed desireSpeed) {
	WheelsSpeed speedDifference = desireSpeed - actualSpeed;
	PIRegulatorValue.integralPartLeft += speedDifference.left;
	PIRegulatorValue.integralPartRight += speedDifference.right;

	int speedLeft = PIRegulatorValue.P * speedDifference.left + PIRegulatorValue.I * PIRegulatorValue.integralPartLeft;
	int speedRight = PIRegulatorValue.P * speedDifference.right + PIRegulatorValue.I * PIRegulatorValue.integralPartRight;

	// set in boundaries
	motorsPower speedMotors;
	speedMotors.left = basic_robotic_fce::valueInRange<int>(speedLeft, diffChassisParam.driver->getMaxPower());
	speedMotors.right = basic_robotic_fce::valueInRange<int>(speedRight, diffChassisParam.driver->getMaxPower());

	return speedMotors;
}

void MobDifferencialChassis::updateEncoders(const int period) {
	timeval timer[2];
	//printf("Sleep time: %i \n\r", This->encodersAcquireTime);

	long int lastMicroTime = 1;
	while(!end){
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
		WheelsSpeed copyDesSpeed = desireSpeed;
		speedMutex.unlock();
		
		motorsPower valueMotors = PIRegulator(actualSpeed, copyDesSpeed);
		//printf("Desire speed left: %f right: %f \n\r", This->desireSpeed.left, This->desireSpeed.right);
		
		//printf("Send motor speed left: %i right: %i \n\r", valueMotors.left, valueMotors.right);		

		sendMotorPower(valueMotors);

		gettimeofday(&timer[1], NULL);
		long int microStop = (timer[1].tv_sec * 1000000) + (timer[1].tv_usec);
		long int sleepMicro = period * 1000 - (microStop - microStart);
		lastMicroTime = microStart;

		printf("Usleep time: %li \n\r", sleepMicro);
		std::this_thread::sleep_for(std::chrono::microseconds(sleepMicro));
	}
}

void MobDifferencialChassis::stop() {
	PIRegulatorValue.integralPartLeft = 0;
	PIRegulatorValue.integralPartRight = 0;
	setSpeed(WheelsSpeed(0, 0));
	diffChassisParam.driver->stop();
}

void MobDifferencialChassis::setSpeed(WheelsSpeed speed) {
	speed.left = basic_robotic_fce::valueInRange(speed.left, diffChassisParam.maxSpeed);
	speed.right = basic_robotic_fce::valueInRange(speed.right, diffChassisParam.maxSpeed);
	
	speedMutex.lock();
	desireSpeed = speed;
	speedMutex.unlock();
}

State MobDifferencialChassis::getState() {
	stateMutex.lock();
	State copyState = robotState;
	stateMutex.unlock();

	return copyState;
}

WheelsDistance MobDifferencialChassis::getWheelDistance() {
	stateMutex.lock();
	WheelsDistance copyWheelsDistance = wheelDistance;
	stateMutex.unlock();

	return copyWheelsDistance;
}

float MobDifferencialChassis::getMaxSpeed() {
	return diffChassisParam.maxSpeed;
}

MobDifferencialChassis::~MobDifferencialChassis(){
	end = true;
	loopPidThread.join();
}