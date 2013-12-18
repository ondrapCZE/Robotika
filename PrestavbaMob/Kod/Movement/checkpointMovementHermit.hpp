#ifndef CHECKPOINT_MOVEMENT_H
#define CHECKPOINT_MOVEMENT_H

#include <thread>
#include <atomic>

#include "../DifferencialniPodvozek/basicDifferencialChassis.h"
#include "checkpointMovement.hpp"
#include "../../../obecne/tsqueue.hpp"

class checkpointMovementHermit : public checkpointMovement{
	tsqueue<Checkpoint> checkpointsQueue;
	BasicDifferencialChassis* chassis;
	
	std::atomic<bool> end;
	std::thread moveToCheckpointsThread;
	
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