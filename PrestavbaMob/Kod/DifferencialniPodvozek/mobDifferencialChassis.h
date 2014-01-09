#ifndef DIFFERENCIAL_CHASSIS_H
#define DIFFERENCIAL_CHASSIS_H

#include <string>
#include <thread>
#include <mutex>
#include <atomic>

#include "basicDifferencialChassis.h"
#include "../MotorDriver/motorDriver.hpp"
#include "../Encoder/encoder.hpp"

struct Distance {
	double left;
	double right;

	Distance(double left = 0, double right = 0) : left(left), right(right) {
	};
};

class MobDifferencialChassis : public BasicDifferencialChassis {
	double metersPerTick;

	PIValue PIRegulatorValue;

	State robotState;
	WheelsDistance wheelDistance;
	WheelsSpeed desireSpeed;
	float frontSpeed;
	
	std::atomic<bool> end;
	std::thread loopPidThread;

	std::mutex stateMutex;
	std::mutex speedMutex;

	WheelsDistance computeDistance(Encoders distance);
	WheelsSpeed computeSpeed(WheelsDistance distance, float time); // distance in m and time in sec

	void changeRobotState(WheelsDistance change);

	int sendMotorPower(struct motorsPower speedMotors);
	motorsPower PIRegulator(WheelsSpeed actualSpeed, WheelsSpeed desireSpeed);

	Encoders getChangeOfEncoders();
	void updateEncoders(const int period); // time in ms	
public:

	MobDifferencialChassis(const DiffChassisParam diffChassisParam);
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
	float getSpeed();
	
	~MobDifferencialChassis();
};

#endif
