#ifndef DIFFERENCIAL_CHASSIS_H
#define DIFFERENCIAL_CHASSIS_H

#include <string>
#include <pthread.h>

#include "basicDifferencialChassis.h"
#include "../MotorDriver/motorDriver.hpp"
#include "../Encoder/encoder.hpp"

const float MAX_SPEED = 0.45f;

struct Distance{
	double left;
	double right;

	Distance(double left=0, double right=0) : left(left), right(right){};
};

class MobDifferencialChassis : public BasicDifferencialChassis{
	int encodersAcquireTime;

	DifferencialChassisParameters chassisParam;
        motorDriver* driver;
        encoder* encoderReader;
	double metersPerTick;

	PIValue PIRegulatorValue;

	State robotState;
	WheelDistance wheelDistance;
	Speed desireSpeed;

	pthread_t updateEncodersThreadHandler;

	pthread_mutex_t stateMutex;
	pthread_mutex_t speedMutex;

	WheelDistance computeDistance(Encoders distance);
	Speed computeSpeed(WheelDistance distance, float time); // distance in m and time in sec
	
	void changeRobotState(WheelDistance change);

	int sendMotorPower(struct motorsPower speedMotors);
	motorsPower PIRegulator(Speed actualSpeed, Speed desireSpeed);
        
        Encoders getChangeOfEncoders();
	static void* updateEncodersThread(void* ThisPointer); // time in ms	
public:
	MobDifferencialChassis(encoder* encoderReader, motorDriver* driver);
	//! 
    /*!
		\param differencialChassisParameters an struct DifferencialChassisParameters argument.
	*/
	void setDifferencialChassisParameters(DifferencialChassisParameters differencialChassisParameters);
	//! 
    /*!
		\param speed an struct Speed argument.
    */
        void stop();
        
	void setSpeed(Speed speed);
	//! 
    /*!
		\return actual state of the chassis
	*/
	State getState();

	WheelDistance getWheelDistance();
        
        float getMaxSpeed();
};

#endif
