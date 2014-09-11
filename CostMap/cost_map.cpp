#include "cost_map.hpp"
#include <limits>

using namespace costMap;
using namespace grid;

const float CostMap::EPSILON = 1e-10;

float CostMap::getPayoffFromMove(const unsigned int x, const unsigned int y,
		const unsigned int move) {

	if (!payoffTable_.inGrid(x + moves_[move][1].x, y + moves_[move][1].y)) {
		return std::numeric_limits<float>::min();
	}

	float payoff = payoffTable_.value(x + moves_[move][1].x,
			y + moves_[move][1].y) - 1;

	payoff += 0.05
			* (costMap_.inGrid(x + moves_[move][0].x, y + moves_[move][0].y) ?
					costMap_.value(x + moves_[move][0].x,
							y + moves_[move][0].y) :
					std::numeric_limits<float>::min());
	payoff += 0.9
			* costMap_.value(x + moves_[move][1].x, y + moves_[move][1].y);
	payoff += 0.05
			* (costMap_.inGrid(x + moves_[move][2].x, y + moves_[move][2].y) ?
					costMap_.value(x + moves_[move][2].x,
							y + moves_[move][2].y) :
					std::numeric_limits<float>::min());

	//printf("Payoff [%i,%i] = %f\n", x,y,payoff);
	//printf("Move from [%i,%i] to [%i,%i]\n",x,y,x + moves_[move][1].x,y + moves_[move][1].y);
	return payoff;
}

CostMap::CostMap(Size size, const float resolution) :
		size_(size), resolution_(resolution), costMap_((size.x / resolution),
				(size.y / resolution)), payoffTable_((size.x / resolution),
				(size.y / resolution), 0), moves_ { { Move(-1, 0), Move(-1, 1),
				Move(0, 1) }, { Move(-1, 1), Move(0, 1), Move(1, 1) }, { Move(0,
				1), Move(1, 1), Move(1, 0) }, { Move(-1, -1), Move(-1, 0), Move(
				-1, 1) }, { Move(1, 1), Move(1, 0), Move(1, -1) }, { Move(0,
				-1), Move(-1, -1), Move(-1, 0) }, { Move(1, -1), Move(0, -1),
				Move(-1, -1) }, { Move(1, 0), Move(1, -1), Move(0, -1) } } {

	minPayoff_ = -1;
	gamma_ = 0.95;
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
	costMap_.setAllValues(minPayoff_);

	unsigned int counter = 0;
	bool change = false;

	// recalculate all values in costMap until values not converges or counter is greater than maxCycle
	float error = 0;
	do {
		error = 0;
		for (int y = 0; y < costMap_.height(); ++y) { // walk through all values
			for (int x = 0; x < costMap_.widht(); ++x) {

				float payoff = std::numeric_limits<float>::min();
				for (int index = 0; index < 8; ++index) {
					float tempPayoff = getPayoffFromMove(x, y, index);
					if (payoff < tempPayoff) {
						payoff = tempPayoff;
					}
				}

				float newValue = gamma_ * payoff;
				error += std::abs(newValue - costMap_.value(x, y));
				costMap_.value(x, y) = newValue;

			}
		}

		if(error > EPSILON){
			 change = true;
		}

		// debug
		/*
		 printf("table = [\n");
		 for (int y = 0; y < costMap_.height(); ++y) { // walk through all values
		 for (int x = 0; x < costMap_.widht()-1; ++x) {
		 printf("%f, ",costMap_.value(x,y));
		 }
		 printf("%f;\n",costMap_.value(costMap_.widht() - 1,y));
		 }
		 printf("];\n");
		 printf("surf(table);\n pause();\n");
		 */

	} while (counter++ < maxCycle && change);

	printf("Recalculate done %i cycles \n", counter);
}

Position CostMap::getBestMove(const Position position) {

	unsigned int move = 0;
	float payoff = getPayoffFromMove(position.x / resolution_,
			position.y / resolution_, 0);
	for (unsigned int index = 1; index < 8; ++index) {
		float tempPayoff = getPayoffFromMove(position.x / resolution_,
				position.y / resolution_, index);

		if (tempPayoff > payoff) {
			move = index;
			payoff = tempPayoff;
		}
	}

	return Position(position.x + moves_[move][1].x * resolution_,
			position.y + moves_[move][1].y * resolution_);
}
