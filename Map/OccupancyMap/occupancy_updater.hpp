#ifndef OCCUPANCI_UPDATER_H
#define OCCUPANCI_UPDATER_H

#include "../../obecne/basic.h"
#include "occupancy_map.hpp"

namespace map {
namespace occupancy {

class OccupancyUpdater {
	static const float FREE_PROB;
	static const float OCCUPIED_PROB;

	const Position startPoint_;
	const float alpha_;
	const float distanceToWall_;
	const float maxRange_;
public:
	OccupancyUpdater(const Position &startPoint, const float &alpha,
			const float &distanceToWall, const float &maxRange);
	void updateMap(OccupancyMap &map);
};

}
}

#endif
