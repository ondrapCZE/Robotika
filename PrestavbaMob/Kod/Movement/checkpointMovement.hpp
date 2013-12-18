#ifndef STATE_MOVEMENT_H
#define STATE_MOVEMENT_H

#include <vector>

#include "../../../obecne/basic.h"

struct Vector{
	double x;
	double y;
	
	Vector(double x=0, double y=0) : x(x), y(y){};
};

struct VectorCheckpoint{
	const bool outVectorAssig;
	Position checkpoint;
	Vector outVector;
	
	VectorState(Position checkpoint) : checkpoint(checkpoint), 
	outVectorAssig(false){};
	
	VectorState(Position checkpoint, Vector outVector) : checkpoint(checkpoint), 
	outVector(outVector), outVectorAssig(true){};
};

class stateMovement{
public:
	virtual void addCheckpoint(const VectorCheckpoint &checkpoint)=0;
	virtual void addCheckpoint(const std::vector<VectorCheckpoint> &checkpoints)=0;
	
	virtual State getActualState()=0;
	virtual void clearCheckpoints()=0;
};

#endif