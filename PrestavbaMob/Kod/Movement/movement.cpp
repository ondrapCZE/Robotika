#include "movement.h"
#include "../../../obecne/basic.h"
#include "../../../Tim310_driver/tim310.h"

#include <cmath>
#include <vector>

#include <sys/time.h>
#include <pthread.h>

static const float EPSILON_ANGLE = M_PI / 360.0f;
static const float EPSILON_DISTANCE = 0.01f;
static const int SLEEP_TIME = 20000; // us
static const float SPEED_STEP = 0.03f;

Movement::Movement(BasicDifferencialChassis* chassis) : chassis(chassis) {

}

void Movement::rotate(float angle){
	finalState = chassis->getState();
	finalState.angle += angle;
	
	State chassisState = chassis->getState();
	float angleDifference = chassisState.angle - finalState.angle;
	float maxSpeed = SPEED_STEP;
	//printf("Angle difference: %f epsilon: %f \n", angleDifference, EPSILON_ANGLE);
	while(std::abs(angleDifference) > EPSILON_ANGLE){
		float motorSpeed = basic_robotic_fce::valueInRange(MAX_SPEED * angleDifference, maxSpeed);
		
		//printf("Angle difference: %f , speed: %f \n", angleDifference, motorSpeed);
		chassis->setSpeed(Speed(motorSpeed , -motorSpeed));

		chassisState = chassis->getState();
		angleDifference = chassisState.angle - finalState.angle;
		
		maxSpeed += SPEED_STEP;
		if(maxSpeed > MAX_SPEED){
			maxSpeed = MAX_SPEED;
		}
	
		usleep(SLEEP_TIME);
	}
}

void Movement::moveStraight(float meter){
	WheelDistance finalWheelDistance = chassis->getWheelDistance();
	finalWheelDistance.left += meter;
	finalWheelDistance.right += meter;

	float differenceLeft = meter;
	float differenceRight = meter;
	float maxSpeed = SPEED_STEP;
	while((std::abs(differenceLeft) > EPSILON_DISTANCE) || (std::abs(differenceRight) > EPSILON_DISTANCE)){	
		WheelDistance wheelDistance = chassis->getWheelDistance();
		differenceLeft = finalWheelDistance.left - wheelDistance.left;
		differenceRight = finalWheelDistance.right - wheelDistance.right;
		float meanDifference = (differenceLeft + differenceRight) / 2.0f;

		float speed = basic_robotic_fce::valueInRange(meanDifference * maxSpeed * 10, maxSpeed);
		//printf("Basic speed %f MaxSpeed %f  \n",speed,maxSpeed);
		// slow down whell with greater distance and speed up wheel with smaller distance

		float speedLeft = speed + (differenceLeft - meanDifference) / (SLEEP_TIME / 1000000.0f);
		float speedRight = speed + (differenceRight - meanDifference) / (SLEEP_TIME / 1000000.0f); 
		//printf("Speed [%f,%f] \n", speedLeft, speedRight);

		chassis->setSpeed(Speed(speedLeft, speedRight));

		maxSpeed += SPEED_STEP;
		if(maxSpeed >= MAX_SPEED){
			maxSpeed = MAX_SPEED - 0.05f;
		}
	
		//printf("Wheel distance [%f,%f], speed[%f,%f] \n", differenceLeft, differenceRight, speedLeft, speedRight);
		usleep(SLEEP_TIME);
	}
}


