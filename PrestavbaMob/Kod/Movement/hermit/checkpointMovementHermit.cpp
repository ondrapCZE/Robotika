#include <iostream>
#include <cmath>
#include <utility>
#include <limits>

#include "checkpointMovementHermit.hpp"
//#include "movement.h"

Circle checkpointMovementHermit::getCircle(const State& state, const Position& point){
	// compute line on which is placed all circle centers
	Position average = ((Position) state + point)/2;
	float a = point.x - state.x;
	float b = point.y - state.y;
	float c = -a*average.x - b*average.y;
	
	// compute tanget line to the state
	float a_chassis = cos(state.theta);
	float b_chassis = sin(state.theta);
    float c_chassis = -a_chassis*state.x - b_chassis*state.y;
	
	float scale = a*b_chassis - b*a_chassis;
	//printf("Scale %f abs(Scale) %f \n", scale, std::abs(scale));
	Circle circle;
	if(std::abs(scale) > epsilonZero_){
		circle.center.x = (b*c_chassis - c*b_chassis) / scale;
		circle.center.y = (c*a_chassis - a*c_chassis) / scale;
	}else{ // center is in the infinity, lines are parallel
		circle.center.x = std::numeric_limits<int>::max();
		circle.center.y = std::numeric_limits<int>::max();
	}
	
	circle.radius = circle.center.distance(state);
	//printf("Circle [%f,%f] with radius %f \n", circle.center.x, circle.center.y,circle.radius);
	return circle;
}

Vector checkpointMovementHermit::getOutputVector(const Checkpoint &prev, const Checkpoint &next, const float tightness){
	float checkedTightness = rob_fce::valueInRange(tightness, 0.0f, 1.0f);
	Position temp = (next.position - prev.position)*checkedTightness;
	return Vector(temp.x,temp.y);
}

Position checkpointMovementHermit::getPointHermit(const Checkpoint& actual, const Checkpoint& target, const float inter) {
	float checkedInter = rob_fce::valueInRange(inter,0.0f,1.0f);
	float powInter2 = checkedInter*checkedInter;
	float powInter3 = powInter2*checkedInter;
	
	float h1 = 2*powInter3 - 3*powInter2 + 1;
	float h2 = -2*powInter3 + 3*powInter2;
	float h3 = powInter3 - 2*powInter2 + checkedInter;
	float h4 = powInter3 - powInter2;
	
	Position curvePosition = actual.position*h1 + target.position*h2 + actual.outVector*h3 + target.outVector*h4;
	return curvePosition;
}

void checkpointMovementHermit::moveToCheckpoint(const Checkpoint &start,const Checkpoint &end){
	float distance = start.position.distance(end.position);
	float step  = 1.0f / (distance*pointsOnMeter);
	for(float i = step; i <= 1.0f; i+=step){
		Position positionHermit = getPointHermit(start,end,i);
		moveToPosition(positionHermit);
	}
}

void checkpointMovementHermit::moveToPosition(const Position& target){
	State state = chassis_.getState();
	
	while(target.distance(state) > epsilon_){
		Circle circle = getCircle(state,target);
		//printf("Circle [%f,%f] with radius %f \n", circle.center.x , circle.center.y, circle.radius);
		float shorterDiameter = circle.radius - chassis_.getWheelbase()/2.0f;
		float longerDiameter = circle.radius + chassis_.getWheelbase()/2.0f;
		float wheelsRatio = shorterDiameter / longerDiameter;
		//printf("Diameters shorter %f longer %f ratio %f \n", shorterDiameter, longerDiameter, wheelsRatio);

		float targetAngle = rob_fce::angle(state, target);
		float finalAngle = rob_fce::normAngle(targetAngle - state.theta);
		//printf("Angle target %f final %f \n", targetAngle, finalAngle);


		//TODO: fix backward movement if angle is bigger than M_PI_2 !!!
		WheelsSpeed wheelsSpeed;
		if(finalAngle >= 0 && finalAngle <= M_PI_2){
				wheelsSpeed.left = speed_*wheelsRatio;
				wheelsSpeed.right = speed_;
		}else	if(finalAngle < 0 && finalAngle >= -M_PI_2){ // move to the right on the circle
				wheelsSpeed.left = speed_;
				wheelsSpeed.right = speed_*wheelsRatio;
		}else if(finalAngle > M_PI_2 && finalAngle < M_PI){
			wheelsSpeed.left = -speed_*wheelsRatio;
			wheelsSpeed.right = -speed_;
		}else if(finalAngle < -M_PI_2 && finalAngle > -M_PI){
			wheelsSpeed.left = -speed_;
			wheelsSpeed.right = -speed_*wheelsRatio;
		}
		
		if(std::abs(finalAngle) > M_PI_2){
			printf("We test backward motion. \n");

		}
		
		chassis_.setSpeed(wheelsSpeed);
	
		std::this_thread::sleep_for(std::chrono::milliseconds(2));
		state = chassis_.getState();
	}
}

void checkpointMovementHermit::moveToCheckpoints() { 
	Checkpoint last;
	bool robotWaited = true;
	while(!end_){
		Checkpoint target;
		if(checkpointsQueue_.tryPop(target)){
			printf("Move to the [%f,%f] with the output vector [%f,%f] \n", 
							target.position.x, 
							target.position.y,
							target.outVector.x,
							target.outVector.y);

			if(robotWaited){
				State state = chassis_.getState();
				last.position = state;
				last.outVector = Vector(cos(state.theta),sin(state.theta));
			}

			moveToCheckpoint(last,target);
			robotWaited = false;
			last = target;
		}else{
			if(!robotWaited){
				printf("Robot is waiting for next checkpoint.\n");
				chassis_.stop(true);
				robotWaited = true;
			}

			std::this_thread::sleep_for(std::chrono::milliseconds(20));
		}
	}
}

checkpointMovementHermit::checkpointMovementHermit(BasicDifferentialChassis &chassis) : chassis_(chassis) {
	end_ = false;
	speed_ = chassis.getMaxSpeed();
	moveToCheckpointsThread_ = std::move(std::thread(&checkpointMovementHermit::moveToCheckpoints,this));
}

void checkpointMovementHermit::addCheckpoint(const Checkpoint& checkpoint){
	checkpointsQueue_.push(checkpoint);
}

void checkpointMovementHermit::addCheckpoint(const std::vector<Checkpoint>& checkpoints){
	for(auto element : checkpoints){
		checkpointsQueue_.push(element);
	}
}

void checkpointMovementHermit::clearCheckpoints(){
	checkpointsQueue_.clear();
}

checkpointMovementHermit::~checkpointMovementHermit(){
	end_ = true;
	moveToCheckpointsThread_.join();
}
