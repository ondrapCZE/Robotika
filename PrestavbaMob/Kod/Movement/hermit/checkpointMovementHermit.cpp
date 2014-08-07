#include <iostream>
#include <cmath>
#include <utility>
#include <limits>
#include <chrono>

#include "../../../../obecne/basic.h"

#include <sys/time.h>

#include "checkpointMovementHermit.hpp"
//#include "movement.h"

Circle checkpointMovementHermit::getCircle(const State& state,
		const Position& point) {
	// compute line on which is placed all circle centers
	Position average = ((Position) state + point) / 2;
	float a = point.x - state.x;
	float b = point.y - state.y;
	float c = -a * average.x - b * average.y;

	// compute tanget line to the state
	float a_chassis = cos(state.theta);
	float b_chassis = sin(state.theta);
	float c_chassis = -a_chassis * state.x - b_chassis * state.y;

	float scale = a * b_chassis - b * a_chassis;
	//printf("Scale %f abs(Scale) %f \n", scale, std::abs(scale));
	Circle circle;
	if (std::abs(scale) > epsilonZero_) {
		circle.center.x = (b * c_chassis - c * b_chassis) / scale;
		circle.center.y = (c * a_chassis - a * c_chassis) / scale;
		circle.radius = circle.center.distance(state);
	} else { // center is in the infinity, lines are parallel
		circle.center.x = std::numeric_limits<int>::max();
		circle.center.y = std::numeric_limits<int>::max();
		circle.radius = std::numeric_limits<int>::max();
	}

	//printf("Circle [%f,%f] with radius %f \n", circle.center.x, circle.center.y,circle.radius);
	return circle;
}

Vector checkpointMovementHermit::getOutputVector(const Checkpoint &prev,
		const Checkpoint &next, const float tightness) {
	float checkedTightness = rob_fce::valueInRange(tightness, 0.0f, 1.0f);
	Position temp = (next.position - prev.position) * checkedTightness;
	return Vector(temp.x, temp.y);
}

Position checkpointMovementHermit::getPointHermit(const Checkpoint& actual,
		const Checkpoint& target, const float inter) {
	float checkedInter = rob_fce::valueInRange(inter, 0.0f, 1.0f);
	float powInter2 = checkedInter * checkedInter;
	float powInter3 = powInter2 * checkedInter;

	float h1 = 2 * powInter3 - 3 * powInter2 + 1;
	float h2 = -2 * powInter3 + 3 * powInter2;
	float h3 = powInter3 - 2 * powInter2 + checkedInter;
	float h4 = powInter3 - powInter2;

	Position curvePosition = actual.position * h1 + target.position * h2
			+ actual.outVector * h3 + target.outVector * h4;
	return curvePosition;
}

void checkpointMovementHermit::moveToCheckpoint(const Checkpoint &start,
		const Checkpoint &end) {

	float distance = start.position.distance(end.position);
	float step = 1.0f / (distance * pointsOnMeter);

	float s = step;
	timeval timer[2];
	while(chassis_.getState().distance(end.position) > epsilon_) {
		gettimeofday(&timer[0], NULL);
		long int microStart = (timer[0].tv_sec * 1000000) + (timer[0].tv_usec);

		if (pause_) {
			checkpointsQueue_.push_front(end);
			break;
		}

		Position interPosition = getPointHermit(start, end, s);
		while(chassis_.getState().distance(end.position)
				> predictDistance_
				&& chassis_.getState().distance(interPosition)
						< predictDistance_) {
			s += step;
			interPosition = getPointHermit(start, end, s);
		};

		//compute distance between actual robot position and interPosition
		distance = chassis_.getState().distance(interPosition);
		float angle = chassis_.getState().angle(interPosition);
		float diffAngle = rob_fce::normAngle(angle - chassis_.getState().theta);

		if(std::abs(diffAngle) > M_PI_4){
			chassis_.setVelocity(0,diffAngle);
		}else{
			chassis_.setVelocity(distance,diffAngle);
		}

		gettimeofday(&timer[1], NULL);
		long int microStop = (timer[1].tv_sec * 1000000) + (timer[1].tv_usec);
		long int sleepMicro = TIME * 1000 - (microStop - microStart);

		//printf("Usleep time: %li \n\r", sleepMicro);
		std::this_thread::sleep_for(std::chrono::microseconds(sleepMicro));
	}
}

void checkpointMovementHermit::moveToCheckpoints() {
	Checkpoint last;
	bool robotWaited = true;
	while (!end_) {
		Checkpoint target;
		if (!pause_ && checkpointsQueue_.tryPop(target)) {
			printf("Move to the [%f,%f] with the output vector [%f,%f] \n",
					target.position.x, target.position.y, target.outVector.x,
					target.outVector.y);

			if (robotWaited) {
				State state = chassis_.getState();
				last.position = state;
				last.outVector = Vector(cos(state.theta), sin(state.theta));
			}

			moveToCheckpoint(last, target);
			robotWaited = false;
			last = target;
		} else {
			if (!robotWaited) {
				printf("Robot is waiting for next checkpoint.\n");
				chassis_.stop(true);
				robotWaited = true;
			}

			std::this_thread::sleep_for(std::chrono::milliseconds(20));
		}
	}
}

checkpointMovementHermit::checkpointMovementHermit(
		BasicDifferentialChassis &chassis) :
		chassis_(chassis) {
	end_ = false;
	pause_ = false;
	speed_ = chassis.getMaxVelocity();
	moveToCheckpointsThread_ = std::move(
			std::thread(&checkpointMovementHermit::moveToCheckpoints, this));
}

void checkpointMovementHermit::addCheckpoint(const Checkpoint& checkpoint) {
	checkpointsQueue_.push_back(checkpoint);
}

void checkpointMovementHermit::addCheckpoint(
		const std::vector<Checkpoint>& checkpoints) {
	for (auto element : checkpoints) {
		checkpointsQueue_.push_back(element);
	}
}

void checkpointMovementHermit::clearCheckpoints() {
	checkpointsQueue_.clear();
}

void checkpointMovementHermit::pause() {
	pause_ = true;
}

void checkpointMovementHermit::resume() {
	pause_ = false;
}

checkpointMovementHermit::~checkpointMovementHermit() {
	end_ = true;
	moveToCheckpointsThread_.join();
}
