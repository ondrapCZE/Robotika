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
	const float EPSILON = 1e-10;

	State robotState_;
	DistanceWheels wheelsDistance_;
	VelocityWheels wheelsSpeed_;
	VelocityWheels wheelsDesireSpeed_;
	
	std::atomic<bool> end_;
	std::thread loopPidThread_;

	std::mutex stateMutex_;
	std::mutex speedMutex_;

	DistanceWheels computeDistance(Encoders distance);
	VelocityWheels computeSpeed(DistanceWheels distance, float time); // distance in m and time in sec

	void changeRobotState(DistanceWheels change);

	int sendMotorPower(struct motorsPower speedMotors);
	int PIRegulator(const float actualSpeed, const float desireSpeed, PIValue &PIParam);

	Encoders getChangeOfEncoders();
	void updateEncoders(const int period); // time in ms	
public:

	MobDifferentialChassis(DiffChassisParam &diffChassisParam);
	//! 
	/*!
	\param speed an struct Speed argument.
	 */
	void stop(bool slow = false);

	void setVelocity(const VelocityWheels speed);
	void setVelocity(const float distance, const float angle);
	//! 
	/*!
	\return actual state of the chassis
	 */
	State getState();

	DistanceWheels getDistanceWheels();
	VelocityWheels getVelocityWheels();
	
	~MobDifferentialChassis();
};

#endif
