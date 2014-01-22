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
	BasicDifferentialChassis* chassis;
	
	std::atomic<bool> end;
	std::thread moveToCheckpointsThread;
	
	const float epsilon = 0.01;
	const float epsilonZero = 1.0e-10;
	const float speed = 0.3f;
	const unsigned int pointsOnMeter = 10; 
	
	Circle getCircle(const State &state, const Position &point);
	Vector getOutputVector(const Checkpoint &prev, const Checkpoint &next, const float tightness = 0.5f);
	Position getPointHermit(const Checkpoint &actual, const Checkpoint &target, const float inter);
	
	void moveToCheckpoint(const Checkpoint &start,const Checkpoint &end);
	void moveToPosition(const Position &target);
	void moveToCheckpoints();
public:
	checkpointMovementHermit(BasicDifferentialChassis* chassis);
	void addCheckpoint(const Checkpoint &checkpoint);
	void addCheckpoint(const std::vector<Checkpoint> &checkpoints);
	
	State getActualState();
	void clearCheckpoints();
	~checkpointMovementHermit();
};

#endif