#ifndef OCCUPANCY_MAP_H
#define OCCUPANCY_MAP_H

#include "../map_interface.hpp"
#include "../../obecne/basic.h"
#include "../../Grid/grid.hpp"

#define DEBUG

namespace map {
namespace occupancy {

class OccupancyMap: virtual public MapInterface {
	static const float IS_OCCUPIED_VALUE;
	static const float IS_FREE_VALUE;
	static const float DEFAULT_PROB;

	Size size_;
	float resolution_;

	grid::Grid<float> grid_;
public:
	OccupancyMap(const Size size = Size(10, 10), const float resolution = 0.05); // size is in meters and will be recalculate in cells number
	OccupancyMap(const OccupancyMap& map);
	OccupancyMap& operator=(const OccupancyMap& map);

	inline float& map(const double &x, const double &y) {
		return grid_.value(x / resolution_, y / resolution_);
	}
	; // in global coordinates, return value from map
	inline float defaultProb() {
		return DEFAULT_PROB;
	}
	;
	inline float occupied(const Position &point) {
		return 1-(1 / (1 + pow(M_E,grid_.value(point.x / resolution_,
					point.y / resolution_))));
	}
	;
	inline Size size() {
		return size_;
	}
	;
	inline float resolution() {
		return resolution_;
	}
	;

	Interval distanceToNearestObstacle(const Position &point, const float &alpha,
			const float &maxDistance);
};

}
}

#endif
