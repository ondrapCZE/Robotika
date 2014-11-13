#ifndef DIFFERENCIAL_CHASSIS_H
#define DIFFERENCIAL_CHASSIS_H

#include <string>
#include <thread>
#include <mutex>
#include <atomic>

#include "basicDifferencialChassis.h"
#include "../MotorDriver/motorDriver.hpp"
#include "../Encoder/encoder.hpp"

//! Implement basic movement behavior and dead reckoning for mob chassis.
class MobDifferentialChassis : public BasicDifferentialChassis {
	const double EPSILON = 1e-10;
	const double STOP_SPEED = 0.05;

	State robotState_;
	DistanceWheels wheelsDistance_;
	VelocityWheels wheelsSpeed_;
	VelocityWheels wheelsDesireSpeed_;
	
	std::atomic<bool> end_;
	std::thread loopPidThread_;

	std::mutex stateMutex_;
	std::mutex speedMutex_;

	DistanceWheels computeDistance(Encoders distance);
	VelocityWheels computeSpeed(DistanceWheels distance, double time); // distance in m and time in sec

	void changeRobotState(DistanceWheels change);

	int sendMotorPower(struct motorsPower speedMotors);
	int PIRegulator(const double actualSpeed, const double desireSpeed, PIValue &PIParam);

	Encoders getChangeOfEncoders();
	void updateEncoders(const int period); // time in ms	
public:

	MobDifferentialChassis(DiffChassisParam &diffChassisParam);
	void stop(bool slow = false);

	void setVelocity(const VelocityWheels speed);
	void setVelocity(const double distance, const double angle);
	State getState();
	DistanceWheels getDistanceWheels();
	VelocityWheels getVelocityWheels();
	
	//! End pid loop.
	~MobDifferentialChassis();
};

#endif
