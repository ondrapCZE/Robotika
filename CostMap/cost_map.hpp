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
typedef std::pair<Payoff, int> PayoffID;
typedef std::list<PayoffID> Payoffs;

//! Robot move on the grid
struct Move {
	int x;
	int y;
	Move(const int x = 0, const int y = 0) :
			x(x), y(y) {
	}
	;
};

//! Path planning via value iteration.
/*!
 * 	For set of payoff objects it will compute fix best movements for whole space.
 */
class CostMap {
	typedef float Type;
	typedef grid::Grid<Type> Grid;
	typedef std::shared_ptr<Grid> GridPtr;

	int id_;
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

	inline int movePayoff(const unsigned int move){
		return move == 0 ? 0 : -2 - ((move - 1) / 4);
	};
	Type getPayoffFromMove(const unsigned int x, const unsigned int y,
			const unsigned int move, GridPtr costMap);
	void recalculateWorker();
public:
	//! Define space size and discretization factor.
	CostMap(Size size = Size(5, 5), const float resolution = 0.05);
	//! Stop recalculation thread
	~CostMap();

	//! Insert payoff object in value function.
	/*! Payoff object can be negative or positive.
	 * 	It changes payoff function for robot movement.
	 *  \param payoffObject implementation of the payoffObject
	 *  \param store it decides whether inserted payoffObject will be applied once (temporary)
	 *  or in every updatePayoffTable call (permanent)
	 *  \return unique id which can be used in deletePayoffObject for object deletion
	 */
	int addPayoffObject(Payoff payoffObject, bool store = false);
	//! Delete permanent payoff object.
	/*!
	 * \param id permanent object identifier
	 */
	void deletePayoffObject(int id);
	//! Delete all permanent payoff objects.
	void clearPayoffObjects();
	//! Clear payoff function table and reapply on it all permanent payoff objects.
	void updatePayoffTable();
	//! Recalculate value array.
	/*! It will set flag for values array recalculation.
	 * 	Old values array is preserved until end of calculation.
	 * 	When calculation ends old array is swap with new one.
	 * 	Calculation ends when array values converged or cycle counter reached maxCycle.
	 * 	\param maxCycle upper boundary for cycle counter
	 */
	void recalculate(unsigned int maxCycle = 100) {
		if (!recalculation_) {
			cycles_ = maxCycle;
			recalculation_ = true;
		}
	}
	;

	//! Return state of the recalculation thread.
	/*!	True mean recalculating values array.
	 * 	False mean waiting for recalculation.
	 */
	bool isRecalculating() {
		return recalculation_;
	}
	;

	//! Return best next position for robot from inserted position.
	Position getBestMove(const Position position);

	//! Return space size
	inline Size size() {
		return size_;
	}

	//! Return space resolution
	inline float resolution() {
		return resolution_;
	}

	//! Return specific cell value from values array
	/*! It serves for path planning visualization. */
	inline float value(const unsigned int x, const unsigned int y) {
		return costMap_->value(x, y);
	}
};

}

#endif
