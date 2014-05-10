#ifndef OCCUPANCI_UPDATER_H
#define OCCUPANCI_UPDATER_H

#include "../../obecne/basic.h"
#include "occupancy_map.hpp"

namespace map {
namespace occupancy {

class OccupancyUpdater {
	static const float FREE_PROB;
	static const float OCCUPIED_PROB;

	Position startPoint_;
	float alpha_;
	float distanceToWall_;
public:
	OccupancyUpdater(const Position &startPoint, const float &alpha,
			const float &distanceToWall);
	void updateMap(OccupancyMap &map);
};

}
}

#endif
