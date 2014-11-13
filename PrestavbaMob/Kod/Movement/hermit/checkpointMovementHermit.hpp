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

//! Implement transit over inserted checkpoint for differential drive.
/*!
 *  Robot ride on front checkpoint in queue is non blocking and it is performed in separate thread.
 *  This mean that you can call all function who returns execution immediately back.
 */
class checkpointMovementHermit : public checkpointMovement{
	tsqueue<Checkpoint> checkpointsQueue_;
	BasicDifferentialChassis &chassis_;
	
	std::atomic<bool> end_;
	std::atomic<bool> pause_;
	std::atomic<bool> checkpointChanged_;

	std::mutex frontMutex_;

	std::thread moveToCheckpointsThread_;
	


	const unsigned int TIME = 10;
	const double epsilon_ = 0.02;
	const double predictDistance_ = 0.05;
	const double epsilonZero_ = 1.0e-10;
	double speed_ = 0.3f;
	const unsigned int pointsOnMeter = 1000;
	
	enum Direction{
		FORWARD,
		BACKWARD,
		LEFT,
		RIGHT
	};

	Position getPointHermit(const Checkpoint &actual, const Checkpoint &target, const double inter);
	
	void moveToCheckpoint(const Checkpoint &start,const Checkpoint &end);
	void moveToCheckpoints();
public:
	//! Set differential chassis and checkpoint callback
	checkpointMovementHermit(BasicDifferentialChassis &chassis, Callback reachedCheckpointCallback = Callback());
	//! Set stop checkpoint movement thread and wait for its end.
	~checkpointMovementHermit();

	void addCheckpoint(const Checkpoint &checkpoint, bool front=false);
	void addCheckpoint(const std::vector<Checkpoint> &checkpoints, bool front=false);
	
	void skipActualCheckpoint();

	void clearCheckpoints();
	void pause();
	void resume();
};

#endif
