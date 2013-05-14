#include "movement.h"
#include "../../../obecne/basic.h"
#include <cmath>

#include <sys/time.h>

static const float EPSILON_ANGLE = M_PI / 360.0f;
static const float EPSILON_DISTANCE = 0.01f;
static const int SLEEP_TIME = 20000; // us

Movement::Movement(BasicDifferencialChassis* chassis) : chassis(chassis) {

}

void Movement::rotate(float angle){
	finalState = chassis->getState();
	finalState.angle += angle;
	
	State chassisState = chassis->getState();
	float angleDifference = chassisState.angle - finalState.angle;
	printf("Angle difference: %f epsilon: %f \n", angleDifference, EPSILON_ANGLE);
	while(std::abs(angleDifference) > EPSILON_ANGLE){
		float motorSpeed = MAX_SPEED * angleDifference;
		
		printf("Angle difference: %f , speed: %f \n", angleDifference, motorSpeed);
		chassis->setSpeed(Speed(motorSpeed , -motorSpeed));

		chassisState = chassis->getState();
		angleDifference = chassisState.angle - finalState.angle;
		usleep(SLEEP_TIME);
	}
}

void Movement::moveStraight(float meter){
	WheelDistance finalWheelDistance = chassis->getWheelDistance();
	finalWheelDistance.left += meter;
	finalWheelDistance.right += meter;

	float differenceLeft = meter;
	float differenceRight = meter;
	while((std::abs(differenceLeft) > EPSILON_DISTANCE) || (std::abs(differenceRight) > EPSILON_DISTANCE)){	
		WheelDistance wheelDistance = chassis->getWheelDistance();
		differenceLeft = finalWheelDistance.left - wheelDistance.left;
		differenceRight = finalWheelDistance.right - wheelDistance.right;

		float speedLeft = basic_robotic_fce::valueInRange(differenceLeft * MAX_SPEED * 10,MAX_SPEED);
		float speedRight = basic_robotic_fce::valueInRange(differenceRight * MAX_SPEED * 10,MAX_SPEED);

		// slow down whell with greater distance and speed up wheel with smaller distance
		float meanDifference = (differenceLeft + differenceRight) / 2.0f;
		speedLeft += (differenceLeft - meanDifference) / (SLEEP_TIME / 1000000.0f);
		speedRight += (differenceRight - meanDifference) / (SLEEP_TIME / 1000000.0f); 

		chassis->setSpeed(Speed(speedLeft, speedRight));

		printf("Wheel distance [%f,%f], speed[%f,%f] \n", differenceLeft, differenceRight, speedLeft, speedRight);
		usleep(SLEEP_TIME);
	}
}

int main(){
	MobDifferencialChassis mobChassis;
	mobChassis.setSpeed(Speed(0,0));
	Movement test(&mobChassis);
	sleep(2);
	
	for(int i=0; i < 4; ++i){
		test.rotate(M_PI / 2.0f);	
		test.moveStraight(1.0f);	
		mobChassis.setSpeed(Speed(0,0));
		sleep(1);
	}
		

	mobChassis.setSpeed(Speed(0,0));
	sleep(2);
	
	return 0;
}
