#include <iostream>

#include "checkpointMovementHermit.hpp"

Vector checkpointMovementHermit::calculateOutputVector(const Checkpoint &prev, const Checkpoint &next, const float tightness){
	float checkedTightness = basic_robotic_fce::valueInRange(tightness, 0.0f, 1.0f);
	Position temp = (next.position - prev.position)*checkedTightness;
	return Vector(temp.x,temp.y);
}

Position checkpointMovementHermit::calculatePointHermit(const Checkpoint& actual, const Checkpoint& target, const float inter) {
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

//TODO:
void checkpointMovementHermit::moveToCheckpoint(Checkpoint& target){
	State actualState = chassis->getState();
	float distance = hypot(target.position.x - actualState.x, target.position.y - actualState.y);
	while(distance > epsilon){
		float inter = 1 / (distance * pointsOnMeter); // TODO: better calculation
		float speed = chassis->getSpeed();
		
		Checkpoint actual(Position(actualState.x,actualState.y),Vector(speed*cos(actualState.angle),speed*sin(actualState.angle)));
		Position positionHermit = calculatePointHermit(actual,target,inter);
		printf("Hermit curve point [%f,%f]\n",positionHermit.x,positionHermit.y);
		moveToPosition(positionHermit);
		
		actualState = chassis->getState();
		distance = hypot(target.position.x - actualState.x, target.position.y - actualState.y);;
	}
}

void checkpointMovementHermit::moveToPosition(const Position& target){
	State actualState = chassis->getState();
	float distance = hypot(target.x - actualState.x, target.y - actualState.y);
	float angle = basic_robotic_fce::angle(Position(actualState.x,actualState.y),target);
	float angleDistance = (angle*chassis->getWheelbase())/2.0f;
	
	WheelsDistance difference(distance-angleDistance,distance+angleDistance);
	WheelsDistance finale = chassis->getWheelDistance() + difference;
	while(hypot(difference.left,difference.right) > epsilon){		


		difference = finale - chassis->getWheelDistance();
		printf("Actual difference [%f,%f]\n", difference.left, difference.right);
		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}
}

// TODO: calculate output vector for checkpoint
void checkpointMovementHermit::moveToCheckpoints() {
	Checkpoint last;
	Checkpoint target;
	while(!end){
		if(checkpointsQueue.tryPop(target)){
			std::cout << target.position.x << "," << target.position.y << std::endl;
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