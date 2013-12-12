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
	Position checkpoint;
	Vector outVector;
	
	VectorState(Position checkpoint, Vector outVector) : checkpoint(checkpoint), 
	outVector(outVector) {};
};

virtual class stateMovement{
public:
	void addCheckpoint(const VectorCheckpoint &checkpoint);
	void addCheckpoint(const std::vector<VectorCheckpoint> &checkpoints);
	
	State getActualState();
	void clear();
	unsigned int size();
};

#endif