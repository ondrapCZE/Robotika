#ifndef OCCUPANCY_MAP_H
#define OCCUPANCY_MAP_H

#include "../map_interface.hpp"

#define DEBUG

namespace map {
namespace occupancy {

class OccupancyMap: virtual public MapInterface {
	static const double IS_OCCUPIED_VALUE;
	static const double IS_FREE_VALUE;

	unsigned int sizeX_; // number of cells in x axis of the map
	unsigned int sizeY_; // number of cells in y axis of the map
	double resolution_; // cell resolution in meters

	double *map_; // pointer to the map memory
	inline double map(const unsigned int &x, const unsigned &y); // in map coordinates, return value from map
	inline void map(const unsigned &x, const unsigned &y, const double &newValue); // in map coordinates set, value in map
public:
	OccupancyMap(const double resolution = 0.02,const Size size = Size(4,4)); // size is in meters and will be recalculate in cells number
	~OccupancyMap();
	OccupyValue occupied(const Position &point);
	double distanceToNearestObstacle(const Position &point,
			const double &alpha);
	Size size();
	double resolution();
};

}
}

#endif
