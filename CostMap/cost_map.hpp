#ifndef COST_MAP_H
#define COST_MAP_H

#include "../obecne/basic.h"
#include "../Grid/grid.hpp"
#include "PayoffObjects/payoff_object.hpp"
#include "Movements/movements.hpp"

#include <list>
#include <memory>

namespace costMap {

typedef std::shared_ptr<PayoffObject> Payoff;
typedef std::shared_ptr<Movement> Move;
typedef std::list<Payoff> Payoffs;
typedef std::list<Move> Moves;

class CostMap {
	grid::Grid<float> costMap_;
	grid::Grid<float> payoffTable_;

	// values are same for payoffTable_
	Size size_;
	float resolution_; // cell resolution in meters

public:
	CostMap(Size size = Size(5,5), const float resolution = 0.05);
};

}

#endif
