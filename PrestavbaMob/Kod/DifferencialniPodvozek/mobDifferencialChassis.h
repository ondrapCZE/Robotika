#ifndef DIFFERENCIAL_CHASSIS_H
#define DIFFERENCIAL_CHASSIS_H

#include <string>
#include <pthread.h>

#include "basicDifferencialChassis.h"
#include "../MotorDriver/motorDriver.hpp"
#include "../Encoder/encoder.hpp"

const float MAX_SPEED = 0.45f;

struct Distance {
	double left;
	double right;

	Distance(double left = 0, double right = 0) : left(left), right(right) {
	};
};

class MobDifferencialChassis : public BasicDifferencialChassis {
	int encodersAcquireTime;

	DiffChassisParm chassisParam;
	motorDriver* driver;
	encoderReader* encoder;
	double metersPerTick;

	PIValue PIRegulatorValue;

	State robotState;
	WheelsDistance wheelDistance;
	WheelsSpeed desireSpeed;

	pthread_t updateEncodersThreadHandler;

	pthread_mutex_t stateMutex;
	pthread_mutex_t speedMutex;

	WheelsDistance computeDistance(Encoders distance);
	WheelsSpeed computeSpeed(WheelsDistance distance, float time); // distance in m and time in sec

	void changeRobotState(WheelsDistance change);

	int sendMotorPower(struct motorsPower speedMotors);
	motorsPower PIRegulator(WheelsSpeed actualSpeed, WheelsSpeed desireSpeed);

	Encoders getChangeOfEncoders();
	static void* updateEncodersThread(void* ThisPointer); // time in ms	
public:
	MobDifferencialChassis(encoderReader* encoder, motorDriver* driver);
	//! 
	/*!
	\param differencialChassisParameters an struct DifferencialChassisParameters argument.
	 */
	void setDifferencialChassisParameters(DiffChassisParm differencialChassisParameters);
	//! 
	/*!
	\param speed an struct Speed argument.
	 */
	void stop();

	void setSpeed(WheelsSpeed speed);
	//! 
	/*!
	\return actual state of the chassis
	 */
	State getState();

	WheelsDistance getWheelDistance();

	float getMaxSpeed();
};

#endif
