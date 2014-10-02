#include <iostream>
#include <cmath>
#include <utility>
#include <limits>
#include <chrono>

#include "../../../../obecne/basic.h"

#include <sys/time.h>

#include "checkpointMovementHermit.hpp"
//#include "movement.h"

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
	bool change = checkpointChanged_ | pause_ | end_;
	while (chassis_.getState().distance(end.position) > epsilon_ && !change) {
		gettimeofday(&timer[0], NULL);
		long int microStart = (timer[0].tv_sec * 1000000) + (timer[0].tv_usec);

		Position interPosition = getPointHermit(start, end, s);
		while (chassis_.getState().distance(end.position) > predictDistance_
				&& chassis_.getState().distance(interPosition)
						< predictDistance_) {
			s += step;
			interPosition = getPointHermit(start, end, s);
		};

		//compute distance between actual robot position and interPosition
		distance = chassis_.getState().distance(interPosition);
		float angle = chassis_.getState().angle(interPosition);
		float diffAngle = rob_fce::normAngle(angle - chassis_.getState().theta);

		if (std::abs(diffAngle) > M_PI_4) {
			printf("Rotate %f\n",diffAngle);
			chassis_.setVelocity(0, diffAngle);
		} else {
			printf("Go straight %f Rotate %f\n",distance, diffAngle);
			chassis_.setVelocity(distance, diffAngle);
		}

		gettimeofday(&timer[1], NULL);
		long int microStop = (timer[1].tv_sec * 1000000) + (timer[1].tv_usec);
		long int sleepMicro = TIME * 1000 - (microStop - microStart);

		//printf("Usleep time: %li \n\r", sleepMicro);
		std::this_thread::sleep_for(std::chrono::microseconds(sleepMicro));
	}

	if (chassis_.getState().distance(end.position) <= epsilon_) {
		printf("Robot reached checkpoint [%f,%f]\n", end.position.x,
				end.position.y);
		checkpointsQueue_.pop_front();

		if (callback_) {
			if (checkpointsQueue_.empty()) {
				callback_(REACHED_LAST_ONE);
			} else {
				callback_(REACHED);
			}
		}
	}
}

void checkpointMovementHermit::moveToCheckpoints() {
	Checkpoint target;
	Checkpoint last;
	bool incorrectLast = true;
	bool stopRobot = true;

	while (!end_) {

		bool newCheckpoint = false;
		if (!pause_) {
			std::lock_guard < std::mutex > lock(frontMutex_);
			newCheckpoint = checkpointsQueue_.try_front(target);
			checkpointChanged_ = false;
		}

		if (!pause_ && newCheckpoint) {
			printf("Move to the [%f,%f] with the output vector [%f,%f] \n",
					target.position.x, target.position.y, target.outVector.x,
					target.outVector.y);

			if (incorrectLast) {
				State state = chassis_.getState();
				VelocityWheels velocityWheels = chassis_.getVelocityWheels();
				float velocity = (velocityWheels.left + velocityWheels.right)
						/ 2.0;

				last.position = state;
				last.outVector = Vector(cos(state.theta) * velocity,
						sin(state.theta) * velocity);
				incorrectLast = false;
			}

			printf("Last checkpoint [%f,%f] with output vector [%f,%f]\n",last.position.x, last.position.y, last.outVector.x,
					last.outVector.y);
			moveToCheckpoint(last, target);
			stopRobot = true;

			if (checkpointChanged_) {
				incorrectLast = true;
			} else {
				last = target;
			}
		} else {
			if (stopRobot) {
				printf("Robot is waiting for next checkpoint.\n");
				chassis_.stop(true);
				incorrectLast = true;
				stopRobot = false;
			}

			std::this_thread::sleep_for(std::chrono::milliseconds(20));
		}
	}
}

checkpointMovementHermit::checkpointMovementHermit(
		BasicDifferentialChassis &chassis, Callback reachedCheckpointCallback) :
		chassis_(chassis), callback_(reachedCheckpointCallback) {
	end_ = false;
	pause_ = false;
	checkpointChanged_ = false;
	speed_ = chassis.getMaxVelocity();
	moveToCheckpointsThread_ = std::move(
			std::thread(&checkpointMovementHermit::moveToCheckpoints, this));
}

checkpointMovementHermit::~checkpointMovementHermit() {
	end_ = true;
	if (moveToCheckpointsThread_.joinable()) {
		moveToCheckpointsThread_.join();
	}
}

void checkpointMovementHermit::addCheckpoint(const Checkpoint& checkpoint,
bool front) {
	if (front) {
		std::lock_guard < std::mutex > lock(frontMutex_);
		checkpointsQueue_.push_front(checkpoint);
		checkpointChanged_ = true;
	} else {
		checkpointsQueue_.push_back(checkpoint);
	}
}

void checkpointMovementHermit::addCheckpoint(
		const std::vector<Checkpoint>& checkpoints, bool front) {
	if (front) {
		std::lock_guard < std::mutex > lock(frontMutex_);
		for (auto element : checkpoints) {
			checkpointsQueue_.push_front(element);
		}
		checkpointChanged_ = true;
	} else {
		for (auto element : checkpoints) {
			checkpointsQueue_.push_back(element);
		}
	}
}

void checkpointMovementHermit::skipActualCheckpoint() {
	std::lock_guard < std::mutex > lock(frontMutex_);
	checkpointsQueue_.pop_front();
	checkpointChanged_ = true;
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

void checkpointMovementHermit::setCallback(Callback fce) {
	callback_ = fce;
}
