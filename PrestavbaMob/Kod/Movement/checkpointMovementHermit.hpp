#ifndef CHECKPOINT_MOVEMENT_H
#define CHECKPOINT_MOVEMENT_H

#include <thread>
#include <atomic>

#include "../DifferencialniPodvozek/basicDifferencialChassis.h"
#include "checkpointMovement.hpp"
#include "../../../obecne/tsqueue.hpp"
#include "../../../obecne/basic.h"
#include "movement.h"

class checkpointMovementHermit : public checkpointMovement{
	tsqueue<Checkpoint> checkpointsQueue;
	BasicDifferencialChassis* chassis;
	
	std::atomic<bool> end;
	std::thread moveToCheckpointsThread;
	
	const float epsilon = 0.01;
	const float epsilonZero = 1.0e-10;
	const float speed = 0.35f;
	const unsigned int pointsOnMeter = 20; 
	
	Circle getCircle(const State &state, const Position &point);
	Vector getOutputVector(const Checkpoint &prev, const Checkpoint &next, const float tightness = 0.5f);
	Position getPointHermit(const Checkpoint &actual, const Checkpoint &target, const float inter);
	
	void moveToCheckpoint(Checkpoint &target);
	void moveToPosition(const State& state, const Position &target);
	void moveToCheckpoints();
public:
	checkpointMovementHermit(BasicDifferencialChassis* chassis);
	void addCheckpoint(const Checkpoint &checkpoint);
	void addCheckpoint(const std::vector<Checkpoint> &checkpoints);
	
	State getActualState();
	void clearCheckpoints();
	~checkpointMovementHermit();
};

#endif