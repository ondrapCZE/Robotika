#include "occupancy_map.hpp"
#include <sstream>
#include <stdexcept>
#include <cmath>

#ifdef DEBUG
	#define TEST_BOUNDARY(X,Y,SIZE_X,SIZE_Y) \
	if(X >= SIZE_X || Y >= SIZE_Y) { \
		std::stringstream msg; \
		msg << "Out of range [" << X << "," << Y << "]"; \
		throw new std::out_of_range(msg.str());\
	}
#else
	#define TEST_BOUNDARY(X,Y,SIZE_X,SIZE_Y)
#endif

using namespace std;
using namespace map;
using namespace map::occupancy;

const float OccupancyMap::IS_OCCUPIED_VALUE = 1e2;
const float OccupancyMap::IS_FREE_VALUE = -1e2;
const float DEFAULT_PROB = 0; // log(0.5/0.5)

//========== public functions ===========
OccupancyMap::OccupancyMap(const float resolution,const Size size) :
	resolution_(resolution), sizeX_(size.x/resolution + 1), sizeY_(size.y/resolution){
	map_ = new float[sizeX_*sizeY_];

	// set zeros in all cells
	for(unsigned int i=0; i<sizeX_; i++){
		for(unsigned int j=0; j<sizeY_; j++){
			map(i,j,0);
		}
	}
}

OccupancyMap::~OccupancyMap(){
	delete[] map_;
}

inline float OccupancyMap::map(const unsigned int &x, const unsigned &y){
	TEST_BOUNDARY(x,y,sizeX_,sizeY_)
	return map_[y*sizeX_ + x];
}

inline void OccupancyMap::map(const unsigned int &x, const unsigned &y, const float &newValue){
	TEST_BOUNDARY(x,y,sizeX_,sizeY_)
	map_[y*sizeX_ + x] = newValue;
}

inline float OccupancyMap::defaultProb(){
	return DEFAULT_PROB;
}

OccupyValue OccupancyMap::occupied(const Position &point) {
	float mapValue = map(point.x,point.y);
	if(mapValue > IS_OCCUPIED_VALUE){
		return OCCUPIED;
	}else if(mapValue < IS_FREE_VALUE){
		return FREE;
	}else{
		return UNKNOWN;
	}
}

float OccupancyMap::distanceToNearestObstacle(const Position &point,
		const float &alpha, const float &maxDistance) {
	float xStep = cos(alpha);
	float yStep = sin(alpha);

	// normalize steps
	float maxStep = max(xStep,yStep);
	xStep /= maxStep;
	yStep /= maxStep;
	float distanceStep = hypot(xStep,yStep)*resolution_;

	float distance = 0;
	float x = point.x;
	float y = point.y;
	while(distance < maxDistance){ // TODO: check distance
		if(map(x,y) > OCCUPIED){
			return distance;
		}
		x+= xStep;
		y+= yStep;
		distance += distanceStep;
	}

	return maxDistance;
}

Size OccupancyMap::size(){
	return Size(sizeX_*resolution_,sizeY_*resolution_);
}

float OccupancyMap::resolution(){
	return resolution_;
}
