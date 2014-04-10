#ifndef CHECKPOINT_MOVEMENT_H
#define CHECKPOINT_MOVEMENT_H

#include <thread>
#include <atomic>

#include "../../DifferencialniPodvozek/basicDifferencialChassis.h"
#include "../checkpointMovement.hpp"
#include "../../../../obecne/tsqueue.hpp"
#include "../../../../obecne/basic.h"
//#include "movement.h"

class checkpointMovementHermit : public checkpointMovement{
	tsqueue<Checkpoint> checkpointsQueue_;
	BasicDifferentialChassis* chassis_;
	
	std::atomic<bool> end_;
	std::thread moveToCheckpointsThread_;
	
	const float epsilon_ = 0.01;
	const float epsilonZero_ = 1.0e-10;
	float speed_ = 0.3f;
	const float speedStep = 0.1f;
	const unsigned int pointsOnMeter = 100; 
	
	Circle getCircle(const State &state, const Position &point);
	Vector getOutputVector(const Checkpoint &prev, const Checkpoint &next, const float tightness = 0.5f);
	Position getPointHermit(const Checkpoint &actual, const Checkpoint &target, const float inter);
	float getSmoothSpeed(float desireSpeed, float actualSpeed);
	
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
