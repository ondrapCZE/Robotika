#ifndef MAP_INTERFACE_H
#define MAP_INTERFACE_H

#include "../obecne/basic.h"

namespace map{

	struct Size{
		double x;
		double y;
		Size(const double x=0,const double y=0) :
			x(x),y(y){};
	};

	class MapInterface{
	public:
		virtual float occupied(const Position &point) = 0;
		virtual float distanceToNearestObstacle(
			const Position &point,
			const float &alpha,
			const float &maxDistance) = 0;
		virtual Size size() = 0;
		virtual float resolution() = 0; // for vector maps is 0
	};
}

#endif
