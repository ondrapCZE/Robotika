#ifndef PAYOFF_OCCUPANCY_MAP_H
#define PAYOFF_OCCUPANCY_MAP_H

#include "../../obecne/basic.h"
#include "payoff_object.hpp"
#include <nav_msgs/OccupancyGrid.h>
#include <cstdint>

namespace costMap {

//! Occupancy map payoff object
class PayoffOccupancyMap: public PayoffObject {
	typedef grid::Grid<uint8_t> Grid;

	static const int FREE;
	static const int UNKNOWN;
	static const int WALL;
	static const int WRONG;

	const nav_msgs::OccupancyGrid& occupancyMap_;
	const Size robotSize_;
	const int wallPayoff_;
	const int unknownPayoff_;
	const int freePayoff_;

	const int transX_;
	const int transY_;

	int payoff(Grid& map, unsigned int x, unsigned int y);
	void updateMap(Grid& map,
			const nav_msgs::OccupancyGrid& occupancyMap,
			const int shiftX, const int shiftY);
	void updateRows(Grid& map, const int step);
	void updateColumns(Grid& map, const int step);
public:
	//! It defines payoff object as occupancy map.
	/*!	\param occupancyMap ROS message for occupancy map
	 * 	\param robotSize robot enclosure block size (used for safe distance from walls)
	 * 	\param wallPayoff payoff value for cells represents wall
	 * 	\param uknownPayoff payoff value for cells represents unknown space
	 * 	\param freePayoff payoff value for cells represents free space
	 * 	\param transX occupancy map shift in x axis relive to payoff array
	 * 	\param transY occupancy map shift in y axis relive to payoff array
	 */
	PayoffOccupancyMap(const nav_msgs::OccupancyGrid& occupancyMap,
			const Size robotSize = Size(0, 0), const int wallPayoff = -1000000,
			const int unknownPayoff = 0, const int freePayoff = 0,
			const int transX = 0, const int transY = 0);
	//! Add payoff value to all cells according to the cells state (free, uknown, wall).
	void updatePayoffTable(Table table, float resolution);
	int getMinPayoff();
};

}

#endif
