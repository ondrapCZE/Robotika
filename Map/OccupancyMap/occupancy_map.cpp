#include "occupancy_map.hpp"
#include <sstream>
#include <stdexcept>

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

using namespace map;
using namespace map::occupancy;

const double OccupancyMap::IS_OCCUPIED_VALUE = 1e2;
const double OccupancyMap::IS_FREE_VALUE = -1e2;

inline double OccupancyMap::map(const unsigned int &x, const unsigned &y){
	TEST_BOUNDARY(x,y,sizeX_,sizeY_)
	return map_[y*sizeX_ + x];
}

inline void OccupancyMap::map(const unsigned int &x, const unsigned &y, const double &newValue){
	TEST_BOUNDARY(x,y,sizeX_,sizeY_)
	map_[y*sizeX_ + x] = newValue;
}

//========== public functions ===========
OccupancyMap::OccupancyMap(const double resolution,const Size size) :
	resolution_(resolution), sizeX_(size.x/resolution + 1), sizeY_(size.y/resolution){
	map_ = new double[sizeX_*sizeY_];
}

OccupancyMap::~OccupancyMap(){
	delete[] map_;
}

OccupyValue OccupancyMap::occupied(const Position &point) {
	double mapValue = map(point.x,point.y);
	if(mapValue > IS_OCCUPIED_VALUE){
		return OCCUPIED;
	}else if(mapValue < IS_FREE_VALUE){
		return FREE;
	}else{
		return UNKNOWN;
	}
}

double OccupancyMap::distanceToNearestObstacle(const Position &point,
		const double &alpha) {
	return 0;
}

Size OccupancyMap::size(){
	return Size(sizeX_*resolution_,sizeY_*resolution_);
}

double OccupancyMap::resolution(){
	return resolution_;
}
