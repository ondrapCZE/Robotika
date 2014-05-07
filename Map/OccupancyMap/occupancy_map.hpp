#ifndef OCCUPANCY_MAP_H
#define OCCUPANCY_MAP_H

#include "../map_interface.hpp"

namespace map{
namespace occupancy{

	class OccupancyMap : virtual public MapInterface{
	public:
		bool occupied(const Position &point);
                double distanceToNearestObstacle(
	                const Position &point,
                        const double &alpha);
	};

}
}

#endif
