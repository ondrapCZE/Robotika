#ifndef MAP_INTERFACE_H
#define MAP_INTERFACE_H

#include "../obecne/basic.h"

namespace map{

	//! Represent wall interval in map
	struct Interval{
		float begin;
		float end;

		Interval(const float begin = 0,const float end = 0) : begin(begin), end(end) {};
	};

	//! Basic operation over map.
	/*! Positions are in meters. */
	class MapInterface{
	public:
		virtual ~MapInterface(){};
		//! Return true if point is in map
		virtual bool inMap(const Position &point) = 0;
		//! Return occupancy probability of the desire point
		virtual float occupied(const Position &point) = 0;
		//! Distance to nearest obstacle.
		/*! \param point find wall from this position
		 *  \param alpha direction in which we find wall
		 *  \param maxDistance max distance from point in which we search
		 */
		virtual Interval distanceToNearestObstacle(
			const Position &point,
			const float &alpha,
			const float &maxDistance) = 0;
		//! Map size
		virtual Size size() = 0;
		//! Map cell size if is bitmap
		virtual float resolution() = 0; // for vector maps is 0
	};
}

#endif
