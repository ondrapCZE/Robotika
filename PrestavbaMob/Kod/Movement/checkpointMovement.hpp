#ifndef STATE_MOVEMENT_H
#define STATE_MOVEMENT_H

#include <vector>
#include <functional>

#include "../../../obecne/basic.h"

//! Describes transit point for robot in plane.
/*!
 * 	Checkpoint is defined by position in plane and output vector.
 * 	Output vector specifying output direction for robots front.
 */
struct Checkpoint {
	Position position;
	Vector outVector;

	Checkpoint(Position position = Position(), Vector outVector = Vector()) :
			position(position), outVector(outVector) {
	}
	;
};

//! Enum describe possible states for checkpoint queue
enum CheckpointReachedState {
	NO_REACHED = 0, REACHED = 1, REACHED_LAST_ONE = 2
};

//! Define callback function type returning state of the checkpoint queue
typedef std::function<void(CheckpointReachedState)> Callback;

//! General checkpoint movement functions.
class checkpointMovement {
protected:
	Callback callback_;
public:
	checkpointMovement(Callback reachedCheckpointCallback = Callback()) :
			callback_(reachedCheckpointCallback) {
	}
	;
//! Virtual destructor can be overwritten by derived class.
	virtual ~checkpointMovement() {
	}
	;

//! Insert transit checkpoint in queue
	/*!
	 * 	\param checkpoint transit checkpoint for robot
	 * 	\param front distinguish between inserting checkpoint in front or end of checkpoint queue
	 */
	virtual void addCheckpoint(const Checkpoint &checkpoint,
			bool front = false)=0;
//! Insert transit checkpoints in queue
	/*!
	 * 	\param checkpoints transit checkpoints for robot
	 * 	\param front distinguish between inserting checkpoints in front or end of checkpoint queue
	 */
	virtual void addCheckpoint(const std::vector<Checkpoint> &checkpoints,
			bool front = false)=0;

//! Remove actual front checkpoint from queue and stop movement on it.
	virtual void skipActualCheckpoint()=0;
//! Remove all checkpoints from queue
	virtual void clearCheckpoints()=0;
//! Pause movement on front checkpoint
	virtual void pause()=0;
//! Resume movement on front checkpoint
	virtual void resume()=0;
//! Set callback which will be call after checkpoint have been reached.
	virtual void setCallback(Callback fce){callback_ = fce;};
};

#endif
