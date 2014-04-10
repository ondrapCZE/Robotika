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

class MobDifferentialChassis : public BasicDifferentialChassis {
	double metersPerTick_;

	PIValue PIParamLeft_;
	PIValue PIParamRight_;

	State robotState_;
	WheelsDistance wheelsDistance_;
	WheelsSpeed wheelsSpeed_;
	WheelsSpeed wheelsDesireSpeed_;
	
	std::atomic<bool> end_;
	std::thread loopPidThread_;

	std::mutex stateMutex_;
	std::mutex speedMutex_;

	WheelsDistance computeDistance(Encoders distance);
	WheelsSpeed computeSpeed(WheelsDistance distance, float time); // distance in m and time in sec

	void changeRobotState(WheelsDistance change);

	int sendMotorPower(struct motorsPower speedMotors);
	int PIRegulator(const float actualSpeed, const float desireSpeed, PIValue &PIParam);

	Encoders getChangeOfEncoders();
	void updateEncoders(const int period); // time in ms	
public:

	MobDifferentialChassis(const DiffChassisParam diffChassisParam);
	//! 
	/*!
	\param speed an struct Speed argument.
	 */
	void stop();

	void setSpeed(const WheelsSpeed speed);
	void setSpeed(const float left, const float right){ setSpeed(WheelsSpeed(left,right)); };
	//! 
	/*!
	\return actual state of the chassis
	 */
	State getState();

	WheelsDistance getWheelDistance();
	WheelsSpeed getSpeed();
	
	~MobDifferentialChassis();
};

#endif
