#ifndef OCCUPANCY_MAP_H
#define OCCUPANCY_MAP_H

#include "../map_interface.hpp"

#define DEBUG

namespace map {
namespace occupancy {

class OccupancyMap: virtual public MapInterface {
	static const float IS_OCCUPIED_VALUE;
	static const float IS_FREE_VALUE;
	static const float DEFAULT_PROB;

	unsigned int sizeX_; // number of cells in x axis of the map
	unsigned int sizeY_; // number of cells in y axis of the map
	float resolution_; // cell resolution in meters

	float *map_; // pointer to the map memory
public:
	OccupancyMap(const float resolution = 0.02, const Size size = Size(4, 4)); // size is in meters and will be recalculate in cells number
	~OccupancyMap();
	inline float map(const unsigned int &x, const unsigned &y); // in map coordinates, return value from map
	inline void map(const unsigned &x, const unsigned &y,
			const float &newValue); // in map coordinates set, value in map
	inline float defaultProb();
	OccupyValue occupied(const Position &point);
	float distanceToNearestObstacle(const Position &point, const float &alpha,
			const float &maxDistance);
	Size size();
	float resolution();
};

}
}

#endif
