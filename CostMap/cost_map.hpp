#ifndef COST_MAP_H
#define COST_MAP_H

#include "../obecne/basic.h"
#include "../Grid/grid.hpp"
#include "PayoffObjects/payoff_object.hpp"

#include <list>
#include <memory>
#include <mutex>
#include <atomic>
#include <thread>

namespace costMap {

typedef std::shared_ptr<PayoffObject> Payoff;
typedef std::list<Payoff> Payoffs;

struct Move{
	int x;
	int y;
	Move(const int x=0,const int y=0) : x(x), y(y){};
};

class CostMap {
	typedef float Type;
	typedef grid::Grid<Type> Grid;
	typedef std::shared_ptr<Grid> GridPtr;

	unsigned int cycles_;
	GridPtr costMap_;
	GridPtr tempCostMap_;
	grid::Grid<int> payoffTable_;

	static const float EPSILON;

	Payoffs payoffObjects_;
	Move moves_[9][3];

	std::thread recalculateThread_;

	std::atomic<bool> recalculation_;
	std::atomic<bool> end_;
	std::mutex costMapMutex_;

	// values are same for payoffTable_
	Size size_;
	float resolution_; // cell resolution in meters

	int minPayoff_;
	float gamma_;

	Type getPayoffFromMove(const unsigned int x, const unsigned int y, const unsigned int move, GridPtr costMap);
	void recalculateWorker();
public:
	CostMap(Size size = Size(5,5), const float resolution = 0.05);
	~CostMap();

	void addPayoffObject(Payoff payoffObject, bool store = false);
	void clearPayoffObjects();
	void updatePayoffTable();
	void recalculate(unsigned int maxCycle = 100){ if(!recalculation_){cycles_=maxCycle;recalculation_ = true;}};
	bool isRecalculating(){ return recalculation_; };
	Position getBestMove(const Position position);

	inline Size size(){
		return size_;
	}

	inline float resolution(){
		return resolution_;
	}

	inline float value(const unsigned int x, const unsigned int y){
		return costMap_->value(x,y);
	}
};

}

#endif
