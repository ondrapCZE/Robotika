#ifndef MAP_INTERFACE_H
#define MAP_INTERFACE_H

#include "../obecne/basic.h"

namespace map{
	class MapInterface{
	public:
		virtual bool occupied(const Position &point) = 0;
		virtual double distanceToNearestObstacle(
			const Position &point,
			const double &alpha) = 0;
	};
}

#endif
