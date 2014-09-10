#ifndef CHECKPOINT_MOVEMENT_H
#define CHECKPOINT_MOVEMENT_H

#include <thread>
#include <atomic>
#include <mutex>

#include "../../DifferencialniPodvozek/basicDifferencialChassis.h"
#include "../checkpointMovement.hpp"
#include "../../../../obecne/tsqueue.hpp"
#include "../../../../obecne/basic.h"
//#include "movement.h"

class checkpointMovementHermit : public checkpointMovement{
	tsqueue<Checkpoint> checkpointsQueue_;
	BasicDifferentialChassis &chassis_;
	
	std::atomic<bool> end_;
	std::atomic<bool> pause_;
	std::atomic<bool> frontChange_;

	std::mutex frontMutex_;

	std::thread moveToCheckpointsThread_;
	
	const unsigned int TIME = 10;
	const float epsilon_ = 0.02;
	const float predictDistance_ = 0.05;
	const float epsilonZero_ = 1.0e-10;
	float speed_ = 0.3f;
	const unsigned int pointsOnMeter = 1000;
	
	Position getPointHermit(const Checkpoint &actual, const Checkpoint &target, const float inter);
	
	void moveToCheckpoint(const Checkpoint &start,const Checkpoint &end);
	void moveToCheckpoints();
public:
	checkpointMovementHermit(BasicDifferentialChassis &chassis);
	void addCheckpoint(const Checkpoint &checkpoint, bool front=false);
	void addCheckpoint(const std::vector<Checkpoint> &checkpoints, bool front=false);
	
	void skipActualCheckpoint();

	void clearCheckpoints();
	void pause();
	void resume();
	~checkpointMovementHermit();
};

#endif
