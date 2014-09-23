#include "payoff_occupancy_map.hpp"
#include <algorithm>
using namespace costMap;

const int PayoffOccupancyMap::FREE = 0;
const int PayoffOccupancyMap::UNKNOWN = 1;
const int PayoffOccupancyMap::WALL = 2;
const int PayoffOccupancyMap::WRONG = 255;

int PayoffOccupancyMap::payoff(Grid& map, unsigned int x, unsigned int y) {
	switch (map.value(x, y)) {
	case FREE: // free value < 25
		return freePayoff_;
		break;
	case UNKNOWN: // unknown value > 25 && value < 75
		return unknownPayoff_;
		break;
	case WALL: // wall value > 75
		return wallPayoff_;
		break;
	default: // wrong value greater than 100 or less than 0
		return 0;
		break;
	}
}

void PayoffOccupancyMap::updateMap(Grid& map,
		const nav_msgs::OccupancyGrid& occupancyMap, const int shiftX,
		const int shiftY) {
	for (unsigned int y = 0; y < map.widht(); ++y) {
		int shiftOccup = (y + shiftY) * occupancyMap_.info.width;
		for (unsigned int x = 0; x < map.height(); ++x) {
			uint8_t valueOcc = occupancyMap_.data[shiftOccup + x + shiftX];
			map.value(x, y) = (valueOcc < 0 && valueOcc > 100) ? WRONG :
								(valueOcc <= 25) ? FREE :
								(valueOcc <= 75) ? UNKNOWN : WALL;
		}
	}
}

void PayoffOccupancyMap::updateRows(Grid& map, const int step) {
	for (unsigned int y = 0; y < map.widht(); ++y) {
		int wall = 0;
		int distance = 0;
		for (unsigned int x = 0; x < map.height(); ++x) {
			if (map.value(x, y) == WALL) {
				wall = step + 1;

				// go back and mark free and unknown space as wall
				distance = std::min(distance, step);
				for (int j = 1; j <= distance; ++j) {
					map.value(x - j, y) = WALL;
				}
				distance = 0;
			}

			if (wall > 0) {
				map.value(x, y) = WALL;
			}

			--wall;
			++distance;
		}
	}
}

void PayoffOccupancyMap::updateColumns(Grid& map, const int step) {
	for (unsigned int x = 0; x < map.height(); ++x) {
		int wall = 0;
		int distance = 0;
		for (unsigned int y = 0; y < map.widht(); ++y) {

			if (map.value(x, y) == WALL) {
				wall = step + 1;

				distance = std::min(distance, step);
				for (int j = 1; j <= distance; ++j) {
					map.value(x, y - j) = WALL;
				}
				distance = 0;
			}

			if (wall > 0) {
				map.value(x, y) = WALL;
			}

			--wall;
			++distance;
		}
	}
}

PayoffOccupancyMap::PayoffOccupancyMap(
		const nav_msgs::OccupancyGrid& occupancyMap,
		const Size robotSize, const int wallPayoff, const int unknownPayoff,
		const int freePayoff, const int transX, const int transY) :
		occupancyMap_(occupancyMap), robotSize_(robotSize), wallPayoff_(
				wallPayoff), unknownPayoff_(unknownPayoff), freePayoff_(
				freePayoff), transX_(transX), transY_(transY) {

}

void PayoffOccupancyMap::updatePayoffTable(Table table, float resolution) {
	const unsigned int occuMaxX = occupancyMap_.info.width + transX_;
	const unsigned int occuMaxY = occupancyMap_.info.height + transY_;
	if (transX_ < table.widht() && transY_ < table.height() && occuMaxX > 0
			&& occuMaxY > 0) {

		unsigned int costX = (transX_ >= 0 ? transX_ : 0);
		unsigned int occuX = (transX_ >= 0 ? 0 : -transX_);
		unsigned int costY = (transY_ >= 0 ? transY_ : 0);
		unsigned int occuY = (transY_ >= 0 ? 0 : -transY_);

		unsigned int stepX = std::min(occuMaxX, table.widht())
				- std::max(0, transX_);
		unsigned int stepY = std::min(occuMaxY, table.height())
				- std::max(0, transY_);

		unsigned int robotX = robotSize_.x / resolution;
		unsigned int robotY = robotSize_.y / resolution;

		Grid map(stepX, stepY, 0);
		updateMap(map, occupancyMap_, occuX, occuY);

		if (robotX > 0) {
			updateRows(map, robotX);
		}

		if (robotY > 0) {
			updateColumns(map, robotY);
		}

		//printf("Table \n\n\n\n\n");
		for (unsigned int x = 0; x < stepX; ++x) {
			for (unsigned int y = 0; y < stepY; ++y) {
				table.value(x + costX, y + costY) += payoff(map, x, y);
				//printf("%i\t",table.value(x + costX, y + costY));
			}
			//printf("\n");
		}

	}
}

int PayoffOccupancyMap::getMinPayoff() {
	return std::min(wallPayoff_, std::min(unknownPayoff_, freePayoff_));
}
