#ifndef PAYOFF_OCCUPANCY_MAP_H
#define PAYOFF_OCCUPANCY_MAP_H

#include "../../obecne/basic.h"
#include "payoff_object.hpp"
#include <nav_msgs/OccupancyGrid.h>
#include <cstdint>

namespace costMap {

class PayoffOccupancyMap: public PayoffObject {
	typedef grid::Grid<uint8_t> Grid;

	static const int FREE;
	static const int UNKNOWN;
	static const int WALL;
	static const int WRONG;

	const nav_msgs::OccupancyGrid::ConstPtr& occupancyMap_;
	const Size robotSize_;
	const int wallPayoff_;
	const int unknownPayoff_;
	const int freePayoff_;

	const int transX_;
	const int transY_;

	int payoff(Grid& map, unsigned int x, unsigned int y);
	void updateMap(Grid& map,
			const nav_msgs::OccupancyGrid::ConstPtr& occupancyMap,
			const int shiftX, const int shiftY);
	void updateRows(Grid& map, const int step);
	void updateColumns(Grid& map, const int step);
public:
	PayoffOccupancyMap(const nav_msgs::OccupancyGrid::ConstPtr& occupancyMap,
			const Size robotSize = Size(0, 0), const int wallPayoff = -1000,
			const int unknownPayoff = 5, const int freePayoff = 0,
			const int transX = 0, const int transY = 0);
	void updatePayoffTable(Table table, float resolution);
	int getMinPayoff();
};

}

#endif
