#include "occupancy_map.hpp"

using namespace map::occupancy;

//========== public functions ===========
bool OccupancyMap::occupied(const Position &point){
	return false;
}

double OccupancyMap::distanceToNearestObstacle(const Position &point,
                        	 const double &alpha){
	return 0;
}
