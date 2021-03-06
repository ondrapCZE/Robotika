#include "movement.h"
#include "../../../../obecne/basic.h"

#include <stdio.h>

#include <cmath>
#include <vector>
#include <algorithm>
#include <thread>

#include <sys/time.h>

static const double EPSILON_ANGLE = M_PI / 360.0f;
static const double EPSILON_DISTANCE = 0.01f;
static const int SLEEP_TIME = 20000; // us
static const double SPEED_STEP = 0.05f;

Movement::Movement(BasicDifferentialChassis* chassis) : chassis(chassis) {
	
}

void Movement::moveCircle(const double &diameter, const double &angle, 
	const Direction &circleDirection){
	
	double shorterDiameter = diameter/2.0f - chassis->getWheelbase()/2.0f;
	double longerDiameter = diameter/2.0f + chassis->getWheelbase()/2.0f;
	double wheelsRatio = shorterDiameter / longerDiameter;
	
	DistanceWheels finalWheelsDistance = chassis->getDistanceWheels();
	switch(circleDirection){
		case LEFT:
			finalWheelsDistance.left += shorterDiameter*angle;
			finalWheelsDistance.right += longerDiameter*angle;
			break;
		case RIGHT:
			finalWheelsDistance.right += shorterDiameter*angle;
			finalWheelsDistance.left += longerDiameter*angle;
			break;
		default:
			break;
	}
	
	double maxSpeed = SPEED_STEP;
	DistanceWheels difference;
	do{
		difference = finalWheelsDistance - chassis->getDistanceWheels();
		double minDistance = std::min(difference.left, difference.right);
		double maxDistance = std::max(difference.left, difference.right);
		double currentRatio = minDistance / maxDistance;
		//printf("Current ratio: %f Default ratio: %f \n\r", currentRatio, wheelsRatio);
		
		double speed = rob_fce::valueInRange(maxDistance * maxSpeed * 10, chassis->getMaxVelocity());
		
		if(circleDirection == LEFT){
			chassis->setVelocity(VelocityWheels(currentRatio*speed, speed));
		}else{
			chassis->setVelocity(VelocityWheels(speed, currentRatio*speed));
		}
		
		maxSpeed = rob_fce::valueInRange(maxSpeed + SPEED_STEP,chassis->getMaxVelocity());
		std::this_thread::sleep_for(std::chrono::microseconds(SLEEP_TIME));
	}while(std::hypot(difference.left,difference.right) > EPSILON_DISTANCE);
	
}

void Movement::moveStraight(const double &meter){
	DistanceWheels finalWheelDistance = chassis->getDistanceWheels();
	finalWheelDistance.left += meter;
	finalWheelDistance.right += meter;

	double maxSpeed = SPEED_STEP;
	DistanceWheels difference;
	do{
		DistanceWheels wheelDistance = chassis->getDistanceWheels();
		difference = finalWheelDistance - wheelDistance;
		double meanDifference = (difference.left + difference.right) / 2.0f;

		double speed = rob_fce::valueInRange(meanDifference * maxSpeed * 15, maxSpeed);
		//printf("Basic speed %f MaxSpeed %f  \n",speed,maxSpeed);
		// slow down whell with greater distance and speed up wheel with smaller distance

		double speedLeft = speed + (difference.left - meanDifference) / (SLEEP_TIME / 1000000.0f);
		double speedRight = speed + (difference.right - meanDifference) / (SLEEP_TIME / 1000000.0f);
		//printf("Speed [%f,%f] \n", speedLeft, speedRight);

		chassis->setVelocity(VelocityWheels(speedLeft, speedRight));

		maxSpeed = rob_fce::valueInRange(maxSpeed + SPEED_STEP,chassis->getMaxVelocity());

		//printf("Wheel distance [%f,%f], speed[%f,%f] \n", difference.left, difference.right, speedLeft, speedRight);
		std::this_thread::sleep_for(std::chrono::microseconds(SLEEP_TIME));
	}while (std::hypot(difference.left,difference.right) > EPSILON_DISTANCE);
}

void Movement::rotate(const double &angle){
	finalState = chassis->getState();
	finalState.theta += angle;

	State chassisState = chassis->getState();
	double angleDifference = chassisState.theta - finalState.theta;
	double maxSpeed = SPEED_STEP;
	//printf("Angle difference: %f epsilon: %f \n", angleDifference, EPSILON_ANGLE);
	while (std::abs(angleDifference) > EPSILON_ANGLE) {
		double motorSpeed = rob_fce::valueInRange(maxSpeed * angleDifference, maxSpeed);

		//printf("Angle difference: %f , speed: %f \n", angleDifference, motorSpeed);
		chassis->setVelocity(VelocityWheels(motorSpeed, -motorSpeed));

		chassisState = chassis->getState();
		angleDifference = chassisState.theta - finalState.theta;

		// create increased ramp
		maxSpeed = rob_fce::valueInRange(maxSpeed + SPEED_STEP,chassis->getMaxVelocity());

		std::this_thread::sleep_for(std::chrono::microseconds(SLEEP_TIME));
	}
}
