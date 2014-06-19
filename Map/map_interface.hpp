#ifndef MAP_INTERFACE_H
#define MAP_INTERFACE_H

#include "../obecne/basic.h"

namespace map{

	struct Interval{
		float begin;
		float end;

		Interval(const float begin = 0,const float end = 0) : begin(begin), end(end) {};
	};

	class MapInterface{
	public:
		virtual float occupied(const Position &point) = 0;
		virtual Interval distanceToNearestObstacle(
			const Position &point,
			const float &alpha,
			const float &maxDistance) = 0;
		virtual Size size() = 0;
		virtual float resolution() = 0; // for vector maps is 0
	};
}

#endif
