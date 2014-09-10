#ifndef STATE_MOVEMENT_H
#define STATE_MOVEMENT_H

#include <vector>

#include "../../../obecne/basic.h"

struct Checkpoint{
	Position position;
	Vector outVector;
	
	Checkpoint(Position position = Position(), Vector outVector = Vector()) : position(position),
	outVector(outVector){};
};

class checkpointMovement{
public:
	virtual ~checkpointMovement(){};

	virtual void addCheckpoint(const Checkpoint &checkpoint, bool front=false)=0;
	virtual void addCheckpoint(const std::vector<Checkpoint> &checkpoints, bool front=false)=0;
	
	virtual void skipActualCheckpoint()=0;
	virtual void clearCheckpoints()=0;
	virtual void pause()=0;
	virtual void resume()=0;
};

#endif
