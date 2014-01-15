#include <iostream>
#include <cmath>

#include "checkpointMovementHermit.hpp"
#include "movement.h"

Circle checkpointMovementHermit::getCircle(const State& state, const Position& point){
	// compute line on which is all circle centers
	Position average = (state.position + point)/2;
	float a = point.x - state.position.x;
	float b = point.y - state.position.y;
	float c = -a*average.x - b*average.y;
	
	// compute tanget line to the state
	float m = std::tan(state.angle + M_PI_2);
	float g = state.position.y - state.position.x*m;
	
	// compute circle center
	Circle circle;
	if(std::abs(b) < epsilon){ // b is near to the zero
		circle.center.x = -c/a;
		circle.center.y = m*circle.center.x + g;
	}else{ // b is greater than zero
		circle.center.x = (-b*g -c)/(a + m);
		circle.center.y = (-a*circle.center.x -c)/b;
	}
	
	circle.radius = circle.center.distance(state.position);
	//printf("Circle [%f,%f] with radius %f \n", circle.center.x, circle.center.y,circle.radius);
	return circle;
}

Vector checkpointMovementHermit::getOutputVector(const Checkpoint &prev, const Checkpoint &next, const float tightness){
	float checkedTightness = basic_robotic_fce::valueInRange(tightness, 0.0f, 1.0f);
	Position temp = (next.position - prev.position)*checkedTightness;
	return Vector(temp.x,temp.y);
}

Position checkpointMovementHermit::getPointHermit(const Checkpoint& actual, const Checkpoint& target, const float inter) {
	float checkedInter = basic_robotic_fce::valueInRange(inter,0.0f,1.0f);
	float powInter2 = checkedInter*checkedInter;
	float powInter3 = powInter2*checkedInter;
	
	float h1 = 2*powInter3 - 3*powInter2 + 1;
	float h2 = -2*powInter3 + 3*powInter2;
	float h3 = powInter3 - 2*powInter2 + checkedInter;
	float h4 = powInter3 - powInter2;
	
	Position curvePosition = actual.position*h1 + target.position*h2 + actual.outVector*h3 + target.outVector*h4;
	return curvePosition;
}

void checkpointMovementHermit::moveToCheckpoint(Checkpoint& target){
	State actualState = chassis->getState();
	float distance = actualState.position.distance(target.position);
	while(distance > epsilon){
		float inter = 1 / (float)(distance * pointsOnMeter); // TODO: better calculation
		float speed = chassis->getSpeed();
		
		Checkpoint actual(actualState.position,Vector(speed*cos(actualState.angle),speed*sin(actualState.angle)));
		Position positionHermit = getPointHermit(actual,target,inter);
		//printf("Hermit curve point [%f,%f]\n",positionHermit.x,positionHermit.y);
		printf("%f %f;\n",positionHermit.x,positionHermit.y);
		moveToPosition(positionHermit);
		
		actualState = chassis->getState();
		distance = actualState.position.distance(target.position);
	}
}

// TODO: FIND ERROR WITH COMPUTATION ANGLE DISTANCE
void checkpointMovementHermit::moveToPosition(const Position& target){
	Circle circle = getCircle(chassis->getState(),target);
	float shorterDiameter = circle.radius - chassis->getWheelbase()/2.0f;
	float longerDiameter = circle.radius + chassis->getWheelbase()/2.0f;
	float wheelsRatio = shorterDiameter / longerDiameter;
	
	//TODO: change this part !!!
	State actualState = chassis->getState();
	//printf("Actual state [%f,%f] angle %f \n", actualState.position.x, actualState.position.y, actualState.angle);
	float m = std::tan(actualState.angle);
	float g = actualState.position.y - m*actualState.position.x;
	float result = circle.center.y + m*circle.center.x + g;
	
	if(result < 0){
		chassis->setSpeed(0.2f,0.2f*wheelsRatio);
	}else{
		chassis->setSpeed(0.2f*wheelsRatio,0.2f);
	}
	
	//printf("%f %f;\n", actualState.position.x,actualState.position.y);
	do{
		std::this_thread::sleep_for(std::chrono::milliseconds(15));
		//printf("%f %f;\n", actualState.position.x,actualState.position.y);
		State actualState = chassis->getState();
	}while((actualState.position.distance(target) < epsilon));
}

void checkpointMovementHermit::moveToCheckpoints() {
	Checkpoint last;
	last.position = chassis->getState().position;
	while(!end){
		Checkpoint target;
		if(checkpointsQueue.tryPop(target)){
			
			if(!target.outVectorAssig){
				Checkpoint next;
				if(checkpointsQueue.tryFront(next)){
					target.outVector = getOutputVector(last,next);
				}
			}
			
			moveToCheckpoint(target);
		}else{		
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
	}
}

checkpointMovementHermit::checkpointMovementHermit(BasicDifferencialChassis* chassis) : chassis(chassis) {
	end = false;
	moveToCheckpointsThread = std::move(std::thread(&checkpointMovementHermit::moveToCheckpoints,this));
}

void checkpointMovementHermit::addCheckpoint(const Checkpoint& checkpoint){
	checkpointsQueue.push(checkpoint);
}

void checkpointMovementHermit::addCheckpoint(const std::vector<Checkpoint>& checkpoints){
	for(auto element : checkpoints){
		checkpointsQueue.push(element);
	}
}

State checkpointMovementHermit::getActualState(){
	return chassis->getState();
}

void checkpointMovementHermit::clearCheckpoints(){
	checkpointsQueue.clear();
}

checkpointMovementHermit::~checkpointMovementHermit(){
	end = true;
	moveToCheckpointsThread.join();
}