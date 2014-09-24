#ifndef OCCUPANCI_UPDATER_H
#define OCCUPANCI_UPDATER_H

#include <sensor_msgs/LaserScan.h>

#include "../../obecne/basic.h"
#include "occupancy_map.hpp"


namespace map {
namespace occupancy {

class OccupancyUpdater {
	static const float FREE_PROB;
	static const float OCCUPIED_PROB;

	const sensor_msgs::LaserScan::ConstPtr& laserScan_;
	const State state_;
	const float minAngle_;
	const float maxAngle_;
	const float maxRange_;

	void oneScanUpdate(OccupancyMap &map, const float &distanceToWall,
			const float &angle);
public:
	OccupancyUpdater(const State &state,
			const sensor_msgs::LaserScan::ConstPtr& laserScan,
			const float &minAngle, const float &maxAngle, const float &maxRange = -1);
	void update(OccupancyMap &map);
};

}
}

#endif
