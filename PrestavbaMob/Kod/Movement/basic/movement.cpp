#include "movement.h"
#include "../../../obecne/basic.h"

#include <stdio.h>

#include <cmath>
#include <vector>
#include <algorithm>
#include <thread>

#include <sys/time.h>

static const float EPSILON_ANGLE = M_PI / 360.0f;
static const float EPSILON_DISTANCE = 0.01f;
static const int SLEEP_TIME = 20000; // us
static const float SPEED_STEP = 0.05f;

Movement::Movement(BasicDifferentialChassis* chassis) : chassis(chassis) {
	
}

void Movement::moveCircle(const float &diameter, const float &angle, 
	const direction &circleDirection){
	
	float shorterDiameter = diameter/2.0f - chassis->getWheelbase()/2.0f;
	float longerDiameter = diameter/2.0f + chassis->getWheelbase()/2.0f;
	float wheelsRatio = shorterDiameter / longerDiameter;
	
	WheelsDistance finalWheelsDistance = chassis->getWheelDistance();
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
	
	float maxSpeed = SPEED_STEP;
	WheelsDistance difference;
	do{
		difference = finalWheelsDistance - chassis->getWheelDistance();
		float minDistance = std::min(difference.left, difference.right);
		float maxDistance = std::max(difference.left, difference.right);
		float currentRatio = minDistance / maxDistance;
		//printf("Current ratio: %f Default ratio: %f \n\r", currentRatio, wheelsRatio);
		
		float speed = rob_fce::valueInRange(maxDistance * maxSpeed * 10, chassis->getMaxSpeed());
		
		if(circleDirection == LEFT){
			chassis->setSpeed(WheelsSpeed(currentRatio*speed, speed));
		}else{
			chassis->setSpeed(WheelsSpeed(speed, currentRatio*speed));
		}
		
		maxSpeed = rob_fce::valueInRange(maxSpeed + SPEED_STEP,chassis->getMaxSpeed());
		std::this_thread::sleep_for(std::chrono::microseconds(SLEEP_TIME));
	}while(std::hypot(difference.left,difference.right) > EPSILON_DISTANCE);
	
}

void Movement::moveStraight(const float &meter){
	WheelsDistance finalWheelDistance = chassis->getWheelDistance();
	finalWheelDistance.left += meter;
	finalWheelDistance.right += meter;

	float maxSpeed = SPEED_STEP;
	WheelsDistance difference;
	do{
		WheelsDistance wheelDistance = chassis->getWheelDistance();
		difference = finalWheelDistance - wheelDistance;
		float meanDifference = (difference.left + difference.right) / 2.0f;

		float speed = rob_fce::valueInRange(meanDifference * maxSpeed * 15, maxSpeed);
		//printf("Basic speed %f MaxSpeed %f  \n",speed,maxSpeed);
		// slow down whell with greater distance and speed up wheel with smaller distance

		float speedLeft = speed + (difference.left - meanDifference) / (SLEEP_TIME / 1000000.0f);
		float speedRight = speed + (difference.right - meanDifference) / (SLEEP_TIME / 1000000.0f);
		//printf("Speed [%f,%f] \n", speedLeft, speedRight);

		chassis->setSpeed(WheelsSpeed(speedLeft, speedRight));

		maxSpeed = rob_fce::valueInRange(maxSpeed + SPEED_STEP,chassis->getMaxSpeed());

		//printf("Wheel distance [%f,%f], speed[%f,%f] \n", difference.left, difference.right, speedLeft, speedRight);
		std::this_thread::sleep_for(std::chrono::microseconds(SLEEP_TIME));
	}while (std::hypot(difference.left,difference.right) > EPSILON_DISTANCE);
}

void Movement::rotate(const float &angle){
	finalState = chassis->getState();
	finalState.theta += angle;

	State chassisState = chassis->getState();
	float angleDifference = chassisState.theta - finalState.theta;
	float maxSpeed = SPEED_STEP;
	//printf("Angle difference: %f epsilon: %f \n", angleDifference, EPSILON_ANGLE);
	while (std::abs(angleDifference) > EPSILON_ANGLE) {
		float motorSpeed = rob_fce::valueInRange(maxSpeed * angleDifference, maxSpeed);

		//printf("Angle difference: %f , speed: %f \n", angleDifference, motorSpeed);
		chassis->setSpeed(WheelsSpeed(motorSpeed, -motorSpeed));

		chassisState = chassis->getState();
		angleDifference = chassisState.theta - finalState.theta;

		// create increased ramp
		maxSpeed = rob_fce::valueInRange(maxSpeed + SPEED_STEP,chassis->getMaxSpeed());

		std::this_thread::sleep_for(std::chrono::microseconds(SLEEP_TIME));
	}
}
