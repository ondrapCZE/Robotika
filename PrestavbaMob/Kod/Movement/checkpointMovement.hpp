#ifndef STATE_MOVEMENT_H
#define STATE_MOVEMENT_H

#include <vector>

#include "../../../obecne/basic.h"

struct Checkpoint{
	bool outVectorAssig;
	Position position;
	Vector outVector;
	
	Checkpoint(Position position = Position()) : position(position), 
	outVectorAssig(false){};
	
	Checkpoint(Position position, Vector outVector) : position(position), 
	outVector(outVector), outVectorAssig(true){};
};

class checkpointMovement{
public:
	virtual void addCheckpoint(const Checkpoint &checkpoint)=0;
	virtual void addCheckpoint(const std::vector<Checkpoint> &checkpoints)=0;
	
	virtual void clearCheckpoints()=0;
};

#endif
