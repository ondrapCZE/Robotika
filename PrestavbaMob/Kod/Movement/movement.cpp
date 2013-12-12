#include "movement.h"
#include "../../../obecne/basic.h"

#include <stdio.h>

#include <cmath>
#include <vector>
#include <algorithm>

#include <sys/time.h>
#include <pthread.h>

static const float EPSILON_ANGLE = M_PI / 360.0f;
static const float EPSILON_DISTANCE = 0.01f;
static const int SLEEP_TIME = 20000; // us
static const float SPEED_STEP = 0.025f;

Movement::Movement(BasicDifferencialChassis* chassis) : chassis(chassis) {
	
}

void Movement::moveCircle(float diameter, float angle, direction circleDirection, float outSpeed){
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
	WheelsDistance differenceDistance;
	do{
		differenceDistance = finalWheelsDistance - chassis->getWheelDistance();
		float minDistance = std::min(differenceDistance.left, differenceDistance.right);
		float maxDistance = std::max(differenceDistance.left, differenceDistance.right);
		float currentRatio = minDistance / maxDistance;
		//printf("Current ratio: %f Default ratio: %f \n\r", currentRatio, wheelsRatio);
		
		float speed = basic_robotic_fce::valueInRange(maxDistance * maxSpeed * 10, chassis->getMaxSpeed());
		
		if(circleDirection == LEFT){
			chassis->setSpeed(WheelsSpeed(currentRatio*speed, speed));
		}else{
			chassis->setSpeed(WheelsSpeed(speed, currentRatio*speed));
		}
		
		maxSpeed = basic_robotic_fce::valueInRange(maxSpeed + SPEED_STEP,chassis->getMaxSpeed());
		usleep(SLEEP_TIME);
	}while((std::abs(differenceDistance.left) > EPSILON_DISTANCE) || (std::abs(differenceDistance.right) > EPSILON_DISTANCE));
	
}

void Movement::moveStraight(float meter, float outSpeed) {
	WheelsDistance finalWheelDistance = chassis->getWheelDistance();
	finalWheelDistance.left += meter;
	finalWheelDistance.right += meter;

	float differenceLeft = meter;
	float differenceRight = meter;
	float maxSpeed = SPEED_STEP;
	while (hypot(differenceLeft,differenceRight) > EPSILON_DISTANCE) {
		WheelsDistance wheelDistance = chassis->getWheelDistance();
		differenceLeft = finalWheelDistance.left - wheelDistance.left;
		differenceRight = finalWheelDistance.right - wheelDistance.right;
		float meanDifference = (differenceLeft + differenceRight) / 2.0f;

		float speed = basic_robotic_fce::valueInRange(meanDifference * maxSpeed * 5 + outSpeed, maxSpeed);
		//printf("Basic speed %f MaxSpeed %f  \n",speed,maxSpeed);
		// slow down whell with greater distance and speed up wheel with smaller distance

		float speedLeft = speed + (differenceLeft - meanDifference) / (SLEEP_TIME / 1000000.0f);
		float speedRight = speed + (differenceRight - meanDifference) / (SLEEP_TIME / 1000000.0f);
		//printf("Speed [%f,%f] \n", speedLeft, speedRight);

		chassis->setSpeed(WheelsSpeed(speedLeft, speedRight));

		maxSpeed = basic_robotic_fce::valueInRange(maxSpeed + SPEED_STEP,chassis->getMaxSpeed());

		printf("Wheel distance [%f,%f], speed[%f,%f] \n", differenceLeft, differenceRight, speedLeft, speedRight);
		usleep(SLEEP_TIME);
	}
}

void Movement::rotate(float angle, float outSpeed) {
	finalState = chassis->getState();
	finalState.angle += angle;

	State chassisState = chassis->getState();
	float angleDifference = chassisState.angle - finalState.angle;
	float maxSpeed = SPEED_STEP;
	//printf("Angle difference: %f epsilon: %f \n", angleDifference, EPSILON_ANGLE);
	while (std::abs(angleDifference) > EPSILON_ANGLE) {
		float motorSpeed = basic_robotic_fce::valueInRange(maxSpeed * angleDifference, maxSpeed);

		printf("Angle difference: %f , speed: %f \n", angleDifference, motorSpeed);
		chassis->setSpeed(WheelsSpeed(motorSpeed, -motorSpeed));

		chassisState = chassis->getState();
		angleDifference = chassisState.angle - finalState.angle;

		// create increased ramp
		maxSpeed = basic_robotic_fce::valueInRange(maxSpeed + SPEED_STEP,chassis->getMaxSpeed());

		usleep(SLEEP_TIME);
	}
}
