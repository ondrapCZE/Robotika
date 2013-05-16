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

Movement::Movement(BasicDifferencialChassis* chassis) : chassis(chassis) {

}

void Movement::rotate(float angle){
	finalState = chassis->getState();
	finalState.angle += angle;
	
	State chassisState = chassis->getState();
	float angleDifference = chassisState.angle - finalState.angle;
	//printf("Angle difference: %f epsilon: %f \n", angleDifference, EPSILON_ANGLE);
	while(std::abs(angleDifference) > EPSILON_ANGLE){
		float motorSpeed = MAX_SPEED * angleDifference;
		
		//printf("Angle difference: %f , speed: %f \n", angleDifference, motorSpeed);
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
		float meanDifference = (differenceLeft + differenceRight) / 2.0f;

		float speed = basic_robotic_fce::valueInRange(meanDifference * MAX_SPEED * 10, MAX_SPEED - 0.05f);

		// slow down whell with greater distance and speed up wheel with smaller distance
		float speedLeft = speed + (differenceLeft - meanDifference) / (SLEEP_TIME / 1000000.0f);
		float speedRight = speed + (differenceRight - meanDifference) / (SLEEP_TIME / 1000000.0f); 

		chassis->setSpeed(Speed(speedLeft, speedRight));

		//printf("Wheel distance [%f,%f], speed[%f,%f] \n", differenceLeft, differenceRight, speedLeft, speedRight);
		usleep(SLEEP_TIME);
	}
}

void* createRecord(void* chassisPointer){
	BasicDifferencialChassis* chassis = (BasicDifferencialChassis*) chassisPointer;	
	unsigned int index = 0;
	
	Tim310_CLASS tim;
	if(!tim.open()){
		printf("Cannot connect tim310\n");
		return  0;
	}

	while(true){
		State state = chassis->getState();
		printf("state %f %f %f \n", state.x, state.y, state.angle);
		if((index%10) == 0){ // write laser scan
			std::vector<uint16_t> laserData = tim.readData();
			printf("laser %d", laserData.size());
			for(unsigned int index = 0; index < laserData.size(); ++index){
				printf(" %d",laserData[index]);
			}

			printf("\n");
		}
		index++;

		usleep(20000);
	}

	return 0;
}

int main(){
	MobDifferencialChassis mobChassis;
	mobChassis.setSpeed(Speed(0,0));
	Movement test(&mobChassis);
	sleep(5);

	pthread_t thread;
	pthread_create(&thread,NULL,&createRecord, (void*) &mobChassis);
	
	test.moveStraight(1.0f);
	//test.rotate(2*M_PI);

	//for(int i=0; i < 4; ++i){		
	//	test.moveStraight(0.70f);
	//	test.rotate(M_PI / 2.0f);
	//	mobChassis.setSpeed(Speed(0,0));
	//	sleep(1);
	//}
		

	mobChassis.setSpeed(Speed(0,0));
	sleep(2);	
	return 0;
}
