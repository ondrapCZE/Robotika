#include "cost_map.hpp"
#include <limits>

using namespace costMap;
using namespace grid;

const float CostMap::EPSILON = 1e-10;

CostMap::Type CostMap::getPayoffFromMove(const unsigned int x,
		const unsigned int y, const unsigned int move, GridPtr costMap) {

	if (!payoffTable_.inGrid(x + moves_[move][1].x, y + moves_[move][1].y)) {
		return std::numeric_limits<Type>::min();
	}

	Type payoff = payoffTable_.value(x + moves_[move][1].x,
			y + moves_[move][1].y) - 1;

	payoff += 0.05
			* (costMap->inGrid(x + moves_[move][0].x, y + moves_[move][0].y) ?
					costMap->value(x + moves_[move][0].x,
							y + moves_[move][0].y) :
					std::numeric_limits<Type>::min());
	payoff += 0.9
			* costMap->value(x + moves_[move][1].x, y + moves_[move][1].y);
	payoff += 0.05
			* (costMap->inGrid(x + moves_[move][2].x, y + moves_[move][2].y) ?
					costMap->value(x + moves_[move][2].x,
							y + moves_[move][2].y) :
					std::numeric_limits<Type>::min());

	//printf("Payoff [%i,%i] = %f\n", x,y,payoff);
	//printf("Move from [%i,%i] to [%i,%i]\n",x,y,x + moves_[move][1].x,y + moves_[move][1].y);
	return payoff;
}

CostMap::CostMap(Size size, const float resolution) :
		size_(size), resolution_(resolution), payoffTable_(
				(size.x / resolution), (size.y / resolution), 0), moves_ { {
				Move(-1, 0), Move(-1, 1), Move(0, 1) }, { Move(-1, 1), Move(0,
				1), Move(1, 1) }, { Move(0, 1), Move(1, 1), Move(1, 0) }, {
				Move(-1, -1), Move(-1, 0), Move(-1, 1) }, { Move(1, 1), Move(1,
				0), Move(1, -1) }, { Move(0, -1), Move(-1, -1), Move(-1, 0) }, {
				Move(1, -1), Move(0, -1), Move(-1, -1) }, { Move(1, 0), Move(1,
				-1), Move(0, -1) } } {

	costMap_ = GridPtr(new Grid((size.x / resolution), (size.y / resolution)));
	tempCostMap_ = GridPtr(
			new Grid((size.x / resolution), (size.y / resolution)));
	minPayoff_ = -1;
	gamma_ = 0.99;
}

void CostMap::addPayoffObject(Payoff payoffObject, bool store) {
	if (minPayoff_ > payoffObject->getMinPayoff()) {
		minPayoff_ = payoffObject->getMinPayoff();
	}

	if (store) {
		payoffObjects_.push_back(payoffObject);
	}

	payoffObject->updatePayoffTable(payoffTable_, resolution_);
}

void CostMap::clearPayoffObjects() {
	payoffObjects_.clear();
}

void CostMap::updatePayoffTable() {
	minPayoff_ = -1;
	payoffTable_.setAllValues(0);

	for (auto payoff : payoffObjects_) {
		if (minPayoff_ > payoff->getMinPayoff()) {
			minPayoff_ = payoff->getMinPayoff();
		}

		payoff->updatePayoffTable(payoffTable_, resolution_);
	}
}

void CostMap::recalculate(unsigned int maxCycle) {
	tempCostMap_->setAllValues(minPayoff_);

	unsigned int counter = 0;
	bool change = false;

	// recalculate all values in costMap until values not converges or counter is greater than maxCycle
	Type error = 0;
	do {
		error = 0;
		for (int y = 0; y < tempCostMap_->height(); ++y) { // walk through all values
			for (int x = 0; x < tempCostMap_->widht(); ++x) {

				Type payoff = std::numeric_limits<Type>::min();
				for (int index = 0; index < 8; ++index) {
					Type tempPayoff = getPayoffFromMove(x, y, index, tempCostMap_);
					if (payoff < tempPayoff) {
						payoff = tempPayoff;
					}
				}

				Type newValue = gamma_ * payoff;
				error += std::abs(newValue - tempCostMap_->value(x, y));
				tempCostMap_->value(x, y) = newValue;

			}
		}

		if (error > EPSILON) {
			change = true;
		}

	} while (counter++ < maxCycle && change);

	std::lock_guard<std::mutex> lock(costMapMutex_);
	costMap_.swap(tempCostMap_);
}

Position CostMap::getBestMove(const Position position) {
	std::lock_guard<std::mutex> lock(costMapMutex_);
	unsigned int move = 0;
	float payoff = getPayoffFromMove(position.x / resolution_,
			position.y / resolution_, 0, costMap_);
	for (unsigned int index = 1; index < 8; ++index) {
		float tempPayoff = getPayoffFromMove(position.x / resolution_,
				position.y / resolution_, index, costMap_);

		if (tempPayoff > payoff) {
			move = index;
			payoff = tempPayoff;
		}
	}

	return Position(position.x + moves_[move][1].x * resolution_,
			position.y + moves_[move][1].y * resolution_);
}
