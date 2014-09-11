#ifndef PAYOFF_OBJECT_H
#define PAYOFF_OBJECT_H

#include "../../Grid/grid.hpp"

namespace costMap{

typedef grid::Grid<int>& Table;

class PayoffObject{
public:
	virtual ~PayoffObject(){};
	virtual void updatePayoffTable(Table table, float resolution) = 0;
	virtual int getMinPayoff() = 0;
};

}

#endif
