#include "payoff_occupancy_map.hpp"
#include <algorithm>
using namespace costMap;

int PayoffOccupancyMap::payoff(unsigned int x, unsigned int y){ // TODO: change this payoff function
	return occupancyMap_->data[y*occupancyMap_->info.width + x] > 75 ? wallPayoff_ : freePayoff_;
}

PayoffOccupancyMap::PayoffOccupancyMap(
		nav_msgs::OccupancyGrid::ConstPtr& occupancyMap, const int wallPayoff,
		const int unknownPayoff, const int freePayoff, const int transX, const int transY) :
		occupancyMap_(occupancyMap), wallPayoff_(wallPayoff), unknownPayoff_(
				unknownPayoff), freePayoff_(freePayoff),transX_(transX), transY_(transY) {

}

void PayoffOccupancyMap::updatePayoffTable(Table table, float resolution) {
	const unsigned int occuMaxX = occupancyMap_->info.width + transX_;
	const unsigned int occuMaxY = occupancyMap_->info.height + transY_;
	if(transX_ < table.widht() && transY_ < table.height() && occuMaxX > 0 && occuMaxY > 0){

		unsigned int costX = (transX_ >= 0 ? transX_ : 0);
		unsigned int occuX = (transX_ >= 0 ? 0 : -transX_);
		unsigned int costY = (transY_ >= 0 ? transY_ : 0);
		unsigned int occuY = (transY_ >= 0 ? 0 : -transY_);

		unsigned int stepX = std::max(0,transX_) - std::min(occuMaxX,table.widht());
		unsigned int stepY = std::max(0,transY_) - std::min(occuMaxY,table.height());

		for(unsigned int x = 0; x < stepX; ++x){
			for(unsigned int y = 0; y < stepY; ++y){
				table.value(x+costX,y+costY) += payoff(x+occuX, y+occuY);
			}
		}

	}
}

int PayoffOccupancyMap::getMinPayoff() {
	return std::min(wallPayoff_, std::min(unknownPayoff_, freePayoff_));
}
