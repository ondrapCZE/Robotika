#include "occupancy_map.hpp"
#include <sstream>
#include <stdexcept>
#include <cmath>

#ifdef DEBUG
	#define TEST_BOUNDARY(X,Y,SIZE_X,SIZE_Y) \
	if(X<0 || Y<0 || X >= SIZE_X || Y >= SIZE_Y) { \
		std::stringstream msg; \
		msg << "Out of range [" << X << "," << Y << "]"; \
		printf(msg.str().c_str()); \
		throw new std::out_of_range(msg.str());\
	}
#else
	#define TEST_BOUNDARY(X,Y,SIZE_X,SIZE_Y)
#endif

using namespace std;
using namespace map;
using namespace map::occupancy;

const float OccupancyMap::IS_OCCUPIED_VALUE = -30;
const float OccupancyMap::IS_FREE_VALUE = 30;
const float OccupancyMap::DEFAULT_PROB = 0; // log(0.5/0.5)

float& OccupancyMap::innerMap(const int &x, const int &y){
	TEST_BOUNDARY(x,y,sizeX_,sizeY_)
	return map_[y*sizeX_ + x];
}

//========== public functions ===========
OccupancyMap::OccupancyMap(const float resolution,const Size size) :
	resolution_(resolution), sizeX_(size.x/resolution + 1), sizeY_(size.y/resolution + 1){
	map_ = new float[sizeX_*sizeY_];

	// set zeros in all cells
	for(unsigned int i=0; i<sizeX_; i++){
		for(unsigned int j=0; j<sizeY_; j++){
			innerMap(i,j) = DEFAULT_PROB;
		}
	}
}

OccupancyMap::~OccupancyMap(){
	delete[] map_;
}

float& OccupancyMap::map(const double &x, const double &y){
	return innerMap(x/resolution_,y/resolution_);
}

float OccupancyMap::defaultProb(){
	return DEFAULT_PROB;
}

float OccupancyMap::occupied(const Position &point) { // TODO: use probabilistic value and return as double
	return 1 - (1 / ( 1 + pow(M_E,map(point.x,point.y))));
}

float OccupancyMap::distanceToNearestObstacle(const Position &point,
		const float &alpha, const float &maxDistance) {
	float xStep = cos(alpha);
	float yStep = sin(alpha);

	// normalize steps
	float maxStep = std::max(std::abs(xStep),std::abs(yStep));
	xStep /= maxStep;
	yStep /= maxStep;
	float distanceStep = hypot(xStep,yStep)*resolution_;

	float distance = 0;
	float x = point.x/resolution_;
	float y = point.y/resolution_;
	while(distance < maxDistance){
		//printf("innerMap[%i,%i] = %f\n",(int)x,(int)y,innerMap(x,y));
		if(innerMap(x,y) < IS_OCCUPIED_VALUE){
			return distance;
		}

		x+= xStep;
		y+= yStep;
		distance += distanceStep;
		//printf("Distance to nearest obstacle step [%f,%f] distance %f \n" , x, y,distance);
	}

	return maxDistance;
}

Size OccupancyMap::size(){
	return Size(((float)sizeX_-1)*resolution_,((float)sizeY_-1)*resolution_);
}

float OccupancyMap::resolution(){
	return resolution_;
}
