#include "cost_map.hpp"
#include <limits>

using namespace costMap;
using namespace grid;

float CostMap::getPayoffFromMove(const unsigned int x, const unsigned int y, const unsigned int move){
	float payoff = payoffTable_.value(x + moves_[move][1].x, y + moves_[move][1].y) - 1;
	payoff += 0.05 * costMap_.value(x + moves_[move][0].x, y + moves_[move][0].y);
	payoff += 0.9 * costMap_.value(x + moves_[move][1].x, y + moves_[move][1].y);
	payoff += 0.05 * costMap_.value(x + moves_[move][2].x, y + moves_[move][2].y);
	return payoff;
}

CostMap::CostMap(Size size, const float resolution) :
		size_(size), resolution_(resolution),
			costMap_(
				(size.x / resolution) + 1, (size.y / resolution) + 1),
			payoffTable_(
				(size.x / resolution) + 1, (size.y / resolution) + 1, 0),
				moves_ {
							{Move(-1,0),Move(-1,1),Move(0,1)},
							{Move(-1,1),Move(0,1),Move(1,1)},
							{Move(0,1),Move(1,1),Move(1,0)},
							{Move(-1,-1),Move(-1,0),Move(-1,1)},
							{Move(1,1),Move(1,0),Move(1,-1)},
							{Move(-1,0),Move(-1,-1),Move(0,-1)},
							{Move(-1,-1),Move(0,-1),Move(1,-1)},
							{Move(0,-1),Move(1,-1),Move(1,0)}
					}
				{

	minPayoff_ = std::numeric_limits<float>::max();
	gamma_ = 0.9;
}

void CostMap::addPayoffObject(Payoff payoffObject, bool store) {
	if (minPayoff_ > payoffObject->getMinPayoff()) {
		minPayoff_ = payoffObject->getMinPayoff();
	}

	if (store) {
		payoffObjects_.push_back(payoffObject);
	}

	payoffObject->updatePayoffTable(payoffTable_,resolution_);
}

void CostMap::updatePayoffTable() {
	payoffTable_.setAllValues(0);

	minPayoff_ = std::numeric_limits<float>::max();

	for (auto payoff : payoffObjects_) {
		if (minPayoff_ > payoff->getMinPayoff()) {
			minPayoff_ = payoff->getMinPayoff();
		}

		payoff->updatePayoffTable(payoffTable_,resolution_);
	}
}

void CostMap::recalculate(unsigned int maxCycle) {
	costMap_.setAllValues(minPayoff_);

	unsigned int counter = 0;
	bool change = true;

	// recalculate all values in costMap until values not converges or counter is greater than maxCycle
	do {
		for(int x=1; x < costMap_.widht() - 1; ++x){ // walk through all values
			for(int y=1; y < costMap_.height() - 1; ++y){

				float payoff = std::numeric_limits<float>::min();
				for(unsigned int index = 0; index < 8; ++index){
					float tempPayoff = getPayoffFromMove(x,y,index);
					if(tempPayoff > payoff){
						payoff = tempPayoff;
					}
				}
				costMap_.value(x,y) = gamma_*payoff;

			}
		}
	} while (counter++ < maxCycle && change);
}

Position CostMap::getBestMove(const Position position) {

	unsigned int move = 0;
	float payoff = std::numeric_limits<float>::min();
	for(unsigned int index = 0; index < 8; ++index){
		float tempPayoff = getPayoffFromMove(
				position.x/resolution_,
				position.y/resolution_,
				index);

		if(tempPayoff > payoff){
			move = index;
			payoff = tempPayoff;
		}
	}

	return Position(
			position.x + moves_[move][1].x*resolution_,
			position.y + moves_[move][1].y*resolution_
			);
}
