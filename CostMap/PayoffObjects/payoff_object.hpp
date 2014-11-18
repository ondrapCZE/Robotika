#ifndef PAYOFF_OBJECT_H
#define PAYOFF_OBJECT_H

#include "../../Grid/grid.hpp"

namespace costMap{

typedef grid::Grid<int>& Table;

//! Represent payoff object which modifies payoff function array.
class PayoffObject{
public:
	//! Virtual destructor can be overwritten in derived class.
	virtual ~PayoffObject(){};
	//! Modify payoff function table.
	/*!	In most cases add values for some payoff function cells.
	 *  \param table payoff function array
	 *  \param resolution is payoff function array resolution
	 */
	virtual void updatePayoffTable(Table table, float resolution) = 0;
	//! Return min from all values which it apply on payoff function array.
	virtual int getMinPayoff() = 0;
};

}

#endif
