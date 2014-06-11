#ifndef PAYOFF_OCCUPANCY_MAP_H
#define PAYOFF_OCCUPANCY_MAP_H

#include "payoff_object.hpp"
#include <nav_msgs/OccupancyGrid.h>

namespace costMap {

class PayoffOccupancyMap {
	const nav_msgs::OccupancyGrid::ConstPtr& occupancyMap_;
	const int wallPayoff_;
	const int unknownPayoff_;
	const int freePayoff_;

	const int transX_;
	const int transY_;

	int payoff(unsigned int x, unsigned int y);
public:
	PayoffOccupancyMap(nav_msgs::OccupancyGrid::ConstPtr& occupancyMap,
			const int wallPayoff = -10, const int unknownPayoff = 0,
			const int freePayoff = 0, const int transX = 0, const int transY = 0);
	void updatePayoffTable(Table table, float resolution);
	int getMinPayoff();
};

}

#endif
