#include "vectorMap.h"

#include <math.h>
using namespace vm;

void VectorMap::addWall(Wall wall){
	walls.push_back(wall);
}

double VectorMap::getNereastDistToWall(Point point, double angle){
	double nearestDistToWall = -1;
	for(wallIt wall = getWallsItBegin(); wall != getWallsItEnd(); wall++){
		double direction = tan(angle);
	}

	return nearestDistToWall;
}

wallIt VectorMap::getWallsItBegin(){
	return walls.begin();
}

wallIt VectorMap::getWallsItEnd(){
	return walls.end();
}