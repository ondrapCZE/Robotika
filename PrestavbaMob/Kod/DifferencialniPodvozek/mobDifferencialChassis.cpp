#include <stdio.h>
#include <stdlib.h>
#include <cmath>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <fcntl.h>

#include "mobDifferencialChassis.h"
#include "../../../obecne/basic.h"

const unsigned int BUFFER_SIZE = 10;
const unsigned int MAX_MOTOR_SPEED = 63;

MobDifferencialChassis::MobDifferencialChassis(encoder* encoderReader, motorDriver* driver) : encoderReader(encoderReader), driver(driver) {

	stateMutex = PTHREAD_MUTEX_INITIALIZER;
	speedMutex = PTHREAD_MUTEX_INITIALIZER;


	// Default value for Mob
	chassisParam.wheelbase = 0.233f;
	chassisParam.wheelRadius = 0.0531f;
	chassisParam.maxSpeed = 0.4f;
	chassisParam.wheelTics = 29696; // Use 10bit resolution encoder and 29:1 gearbox

	metersPerTick = (2 * M_PI * chassisParam.wheelRadius) / (float) chassisParam.wheelTics;

	sendMotorPower(motorsPower(0, 0));

	// Set PIRegulator
	PIRegulatorValue.P = 200; // 740 oscillate value 
	PIRegulatorValue.I = 12;

	encodersAcquireTime = 10; // every x ms
	pthread_create(&updateEncodersThreadHandler, NULL, &updateEncodersThread, (void*) this);
}

WheelDistance MobDifferencialChassis::computeDistance(Encoders distance) {
	WheelDistance distanceInMeters;
	distanceInMeters.left = distance.left * metersPerTick;
	distanceInMeters.right = distance.right * metersPerTick;

	return distanceInMeters;
}

Speed MobDifferencialChassis::computeSpeed(WheelDistance distance, float time) {
	Speed speed;
	speed.left = distance.left / time;
	speed.right = distance.right / time;

	return speed;
}

void MobDifferencialChassis::changeRobotState(WheelDistance change) {
	double angleChange = (change.right - change.left) / chassisParam.wheelbase;
	double distanceChange = (change.right + change.left) / 2;

	pthread_mutex_lock(&stateMutex);
	wheelDistance.left += change.left;
	wheelDistance.right += change.right;

	robotState.x += distanceChange * cos(robotState.angle + (angleChange / 2.0f));
	robotState.y += distanceChange * sin(robotState.angle + (angleChange / 2.0f));
	robotState.angle += angleChange;
	//printf("State [%f,%f,%f] \n\r", robotState.x, robotState.y, robotState.angle);
	pthread_mutex_unlock(&stateMutex);
}

Encoders MobDifferencialChassis::getChangeOfEncoders() {
	return encoderReader->getChangeOfEncoders();
}

int MobDifferencialChassis::sendMotorPower(struct motorsPower speedMotors) {
	return driver->setMotorsPower(speedMotors);
}

motorsPower MobDifferencialChassis::PIRegulator(Speed actualSpeed, Speed desireSpeed) {
	Speed speedDifference = desireSpeed - actualSpeed;
	PIRegulatorValue.integralPartLeft += speedDifference.left;
	PIRegulatorValue.integralPartRight += speedDifference.right;

	int speedLeft = PIRegulatorValue.P * speedDifference.left + PIRegulatorValue.I * PIRegulatorValue.integralPartLeft;
	int speedRight = PIRegulatorValue.P * speedDifference.right + PIRegulatorValue.I * PIRegulatorValue.integralPartRight;

	// set in boundaries
	motorsPower speedMotors;
	speedMotors.left = basic_robotic_fce::valueInRange<int>(speedLeft, MAX_MOTOR_SPEED);
	speedMotors.right = basic_robotic_fce::valueInRange<int>(speedRight, MAX_MOTOR_SPEED);

	return speedMotors;
}

void* MobDifferencialChassis::updateEncodersThread(void* ThisPointer) {
	timeval timer[2];
	MobDifferencialChassis* This = (MobDifferencialChassis *) ThisPointer;
	//printf("Sleep time: %i \n\r", This->encodersAcquireTime);

	long int lastMicroTime = 1;
	while (true) {
		gettimeofday(&timer[0], NULL);
		long int microStart = (timer[0].tv_sec * 1000000) + (timer[0].tv_usec);

		// Get encoders and compute distance
		Encoders differenceEncoders = This->getChangeOfEncoders();

		// Compute actual speed and use PID
		float time = (microStart - lastMicroTime) / 1000000.0f; // time in sec
		WheelDistance distance = This->computeDistance(differenceEncoders);
		Speed actualSpeed = This->computeSpeed(distance, time);
		This->changeRobotState(distance);
		//printf("Actual speed left: %f  right: %f \n\r", actualSpeed.left, actualSpeed.right);

		pthread_mutex_lock(&This->speedMutex);
		motorsPower valueMotors = This->PIRegulator(actualSpeed, This->desireSpeed);
		//printf("Desire speed left: %f right: %f \n\r", This->desireSpeed.left, This->desireSpeed.right);
		pthread_mutex_unlock(&This->speedMutex);
		//printf("Send motor speed left: %i right: %i \n\r", valueMotors.left, valueMotors.right);		

		This->sendMotorPower(valueMotors);

		gettimeofday(&timer[1], NULL);
		long int microStop = (timer[1].tv_sec * 1000000) + (timer[1].tv_usec);
		long int sleepMicro = This->encodersAcquireTime * 1000 - (microStop - microStart);
		lastMicroTime = microStart;

		//printf("Usleep time: %li \n\r", sleepMicro);
		usleep(sleepMicro);
	}

	return 0;
}

void MobDifferencialChassis::setDifferencialChassisParameters(DifferencialChassisParameters differencialChassisParameters) {
	chassisParam = differencialChassisParameters;
	metersPerTick = (2 * M_PI * differencialChassisParameters.wheelRadius) / (double) differencialChassisParameters.wheelTics;
}

void MobDifferencialChassis::stop() {
	PIRegulatorValue.integralPartLeft = 0;
	PIRegulatorValue.integralPartRight = 0;
	setSpeed(Speed(0, 0));
	driver->stop();
}

void MobDifferencialChassis::setSpeed(Speed speed) {
	speed.left = basic_robotic_fce::valueInRange(speed.left, MAX_SPEED);
	speed.right = basic_robotic_fce::valueInRange(speed.right, MAX_SPEED);

	pthread_mutex_lock(&speedMutex);
	desireSpeed = speed;
	pthread_mutex_unlock(&speedMutex);
}

State MobDifferencialChassis::getState() {
	pthread_mutex_lock(&stateMutex);
	State copyState = robotState;
	pthread_mutex_unlock(&stateMutex);

	return copyState;
}

WheelDistance MobDifferencialChassis::getWheelDistance() {
	pthread_mutex_lock(&stateMutex);
	WheelDistance copyWheelDistance = wheelDistance;
	pthread_mutex_unlock(&stateMutex);

	return copyWheelDistance;
}

float MobDifferencialChassis::getMaxSpeed() {
	return chassisParam.maxSpeed;
}

/*
int main(){
				motorDriver* driver = new motorDriverSabertooth("/dev/ttyAMA0");
	MobDifferencialChassis mobChassis("/dev/i2c-1",0x30,driver);
        
				Speed stop(0,0);
	mobChassis.setSpeed(stop);
	sleep(2);
        
				Speed desire(0.2f,0.2f);
	mobChassis.setSpeed(desire);
				sleep(5);
				Speed back(-0.2f,-0.2f);
				mobChassis.setSpeed(back);
				sleep(5);
				mobChassis.setSpeed(stop);
				sleep(1);
        
	return 0;
}
 */