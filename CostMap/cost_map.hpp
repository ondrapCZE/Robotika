#ifndef COST_MAP_H
#define COST_MAP_H

#include "../obecne/basic.h"
#include "../Grid/grid.hpp"
#include "PayoffObjects/payoff_object.hpp"

#include <list>
#include <memory>

namespace costMap {

typedef std::shared_ptr<PayoffObject> Payoff;
typedef std::list<Payoff> Payoffs;

struct Move{
	int x;
	int y;
	Move(const int x=0,const int y=0) : x(x), y(y){};
};

class CostMap {
	grid::Grid<float> costMap_;
	grid::Grid<int> payoffTable_;

	Payoffs payoffObjects_;
	Move moves_[8][3];

	// values are same for payoffTable_
	Size size_;
	float resolution_; // cell resolution in meters

	int minPayoff_;
	float gamma_;

	float getPayoffFromMove(const unsigned int x, const unsigned int y, const unsigned int move);
public:
	CostMap(Size size = Size(5,5), const float resolution = 0.05);

	void addPayoffObject(Payoff payoffObject, bool store = false);
	void updatePayoffTable();
	void recalculate(unsigned int maxCycle = 50);
	Position getBestMove(const Position position);

	inline Size size(){
		return size_;
	}

	inline float resolution(){
		return resolution_;
	}

	inline float value(const unsigned int x, const unsigned int y){
		return costMap_.value(x,y);
	}
};

}

#endif
