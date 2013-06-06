#include "../../PrestavbaMob/Kod/Movement/movement.h"
#include "../../obecne/basic.h"
#include "../../Tim310_driver/tim310.h"

#include <cmath>
#include <vector>
#include <iostream>

#include <sys/time.h>
#include <pthread.h>


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
		double beta =  end.angle - gama;

		std::cout << "a: " << alpha << " l: " << length << " b: " << beta << std::endl;
		movement->rotate(alpha);
		movement->moveStraight(length);
		movement->rotate(beta);
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
		State state

		if((index%10) == 0){ // write laser scan
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

int main(){
	MobDifferencialChassis mobChassis;
	mobChassis.setSpeed(Speed(0,0));
	Movement test(&mobChassis);
	sleep(1);

	pthread_t thread;
	//pthread_create(&thread,NULL,&createRecord, (void*) &mobChassis);

	State end(1.0,0,0);
	moveToPosition(mobChassis.getState(),end,&test);

	end.angle = M_PI;
	moveToPosition(mobChassis.getState(),end,&test);

	
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
