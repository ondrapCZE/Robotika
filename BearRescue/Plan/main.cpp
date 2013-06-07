#include "../../PrestavbaMob/Kod/Movement/movement.h"
#include "../../obecne/basic.h"
#include "../../Tim310_driver/tim310.h"
#include "../FastSlam/fastSlam.h"

#include <cmath>
#include <vector>
#include <iostream>

#include <sys/time.h>
#include <pthread.h>


void moveToPositionEndRotate(State start, State end, Movement *movement){

	double shiftX = end.x - start.x;
	double shiftY = end.y - start.y;
	double length = hypot(shiftX,shiftY);

	if(length == 0){
		// TODO use shorter anglewit
		movement->rotate(end.angle - start.angle);
	}else{
		double gama = asin(shiftY/length);

		if(shiftX < 0){
			gama = M_PI - gama;
		}

		double alpha = gama - start.angle;
		double beta =  end.angle - gama;

		movement->rotate(alpha);
		movement->moveStraight(length);
		movement->rotate(beta);
	}

}

void moveToPosition(State start, State end, Movement *movement){

	double shiftX = end.x - start.x;
	double shiftY = end.y - start.y;
	double length = hypot(shiftX,shiftY);

	if(length == 0){
		// TODO use shorter anglewit
		movement->rotate(end.angle - start.angle);
	}else{
		double gama = asin(shiftY/length);

		if(shiftX < 0){
			gama = M_PI - gama;
		}

		double alpha = gama - start.angle;

		movement->rotate(alpha);
		movement->moveStraight(length);
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
		State state;

		if((index%10) == 9){ // write laser scan
			std::vector<uint16_t> laserData = tim.readData();
			state = chassis->getState();
			printf("laser %d", laserData.size());
			for(unsigned int index = 0; index < laserData.size(); ++index){
				printf(" %d",laserData[index]);
			}

			printf("\n");
		}else{
			state = chassis->getState();
		}

		printf("state %f %f %f \n", state.x, state.y, state.angle);
		index++;

		usleep(20000);
	}

	return 0;
}

struct MclChassis{
	BasicDifferencialChassis* chassis;
	FastSLAM_CLASS*  mcl;
};

void* mclUpdate(void* mclChassisPointer){
	MclChassis* mclChassis = (MclChassis*) mclChassisPointer;

	int count = 0;

	while(true){
		State state = mclChassis->chassis->getState();
		mclChassis->mcl->move(state);
		usleep(10000);
		if((count % 20) == 0){
			State state = mclChassis->mcl->getMostProbabilisticState();
			printf("State [%f,%f,%f]\n", state.x, state.y, state.angle);
		}
	}

	return 0;
}

int main(){
	MobDifferencialChassis mobChassis;
	mobChassis.setSpeed(Speed(0,0));
	Movement test(&mobChassis);
	sleep(1);

	FastSLAM_CLASS mcl;
	mcl.init(50);
	MclChassis mclChassis;
	mclChassis.mcl = &mcl;
	mclChassis.chassis = &mobChassis;	

	pthread_t thread;
	//printf("Create thread\n");
	pthread_create(&thread,NULL,&mclUpdate, (void*) &mclChassis);
	//pthread_create(&thread,NULL,&createRecord, (void*) &mobChassis);

//	printf("Move \n");
	State end(1.0,0,0);
	moveToPosition(mcl.getMostProbabilisticState(),end,&test);

	end.angle = M_PI;
	moveToPosition(mcl.getMostProbabilisticState(),end,&test);

	
	//test.moveStraight(0.70f);
	//test.rotate(-M_PI/2.0f);
	//test.moveStraight(0.42f);
	//test.rotate(-M_PI/2.0f);
	//test.moveStraight(0.40f);
	//test.rotate(M_PI/2.0f);
	//test.moveStraight(0.5f);
	//test.rotate(M_PI/2.0f);
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
