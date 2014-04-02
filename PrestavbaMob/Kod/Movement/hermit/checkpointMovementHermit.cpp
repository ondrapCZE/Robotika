#include <iostream>
#include <cmath>
#include <utility>

#include "checkpointMovementHermit.hpp"
//#include "movement.h"

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
	if(std::abs(b) < epsilonZero){ // b is near to the zero
		circle.center.x = -c/a;
		circle.center.y = m*circle.center.x + g;
	}else{ // b is greater than zero
		circle.center.x = (-b*g -c)/(a + m*b);
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

float checkpointMovementHermit::getSmoothSpeed(float desireSpeed, float actualSpeed){
	float outSpeed = actualSpeed;
	if(desireSpeed > actualSpeed){
		outSpeed += speedStep;
	}else{
		outSpeed -= speedStep; 
	}
	
	return basic_robotic_fce::valueInRange(outSpeed,desireSpeed);
}

void checkpointMovementHermit::moveToCheckpoint(const Checkpoint &start,const Checkpoint &end){
	float distance = start.position.distance(end.position);
	float step  = 1.0f / (distance*pointsOnMeter);
	for(float i = step; i <= 1.0f; i+=step){
		Position positionHermit = getPointHermit(start,end,i);
		//printf("position %f %f %f %f \n",actual.position.x, actual.position.y, actual.outVector.x, actual.outVector.y);
		//printf("hermit %f %f \n",positionHermit.x,positionHermit.y);
		moveToPosition(positionHermit);
	}
}

void checkpointMovementHermit::moveToPosition(const Position& target){
	State state = chassis->getState();
	
	while(target.distance(state.position) > epsilon){
		printf("%f %f;\n",state.position.x, state.position.y);
		Circle circle = getCircle(state,target);
		float shorterDiameter = circle.radius - chassis->getWheelbase()/2.0f;
		float longerDiameter = circle.radius + chassis->getWheelbase()/2.0f;
		float wheelsRatio = shorterDiameter / longerDiameter;

		float targetAngle = basic_robotic_fce::angle(state.position, target);
		float finalAngle = basic_robotic_fce::normAngle(targetAngle - state.angle);

		WheelsSpeed wheelsSpeed;
		if(finalAngle >= 0 && finalAngle <= M_PI_2){
				wheelsSpeed.left = speed*wheelsRatio;
				wheelsSpeed.right = speed;
		}else	if(finalAngle < 0 && finalAngle >= -M_PI_2){ // move to the right on the circle
				wheelsSpeed.left = speed;
				wheelsSpeed.right = speed*wheelsRatio;
		}
		
		if(std::abs(finalAngle) > M_PI_2){
			wheelsSpeed.left = -wheelsSpeed.left;
			wheelsSpeed.right = -wheelsSpeed.right;
		}
		
		//WheelsSpeed actualWheelsSpeed = chassis->getSpeed();
		//wheelsSpeed.left = getSmoothSpeed(wheelsSpeed.left,actualWheelsSpeed.left);
		//wheelsSpeed.right = getSmoothSpeed(wheelsSpeed.right,actualWheelsSpeed.right);
		//printf("Actual speed[%f,%f] \n", wheelsSpeed.left, wheelsSpeed.right);
		
		chassis->setSpeed(wheelsSpeed);
	
		std::this_thread::sleep_for(std::chrono::milliseconds(4));
		state = chassis->getState();
	}
}

void checkpointMovementHermit::moveToCheckpoints() { 
	State state = chassis->getState();
	Checkpoint last;
	last.position = chassis->getState().position; 
	last.outVector = Vector(cos(state.angle),sin(state.angle));
	while(!end){
		Checkpoint target;
		if(checkpointsQueue.tryPop(target)){
			
			if(!target.outVectorAssig){
				Checkpoint next;
				if(checkpointsQueue.tryFront(next)){
					target.outVector = getOutputVector(chassis->getState().position,next);
				}
			}
			
			printf("Move to the [%f,%f] with the output vector [%f,%f] \n", 
							target.position.x, 
							target.position.y,
							target.outVector.x,
							target.outVector.y);
			moveToCheckpoint(last,target);
			last = target;
		}else{		
			//chassis->stop();
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
	}
}

checkpointMovementHermit::checkpointMovementHermit(BasicDifferentialChassis* chassis) : chassis(chassis) {
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