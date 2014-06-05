#ifndef GRID_ITERATOR_H
#define GRID_ITERATOR_H

#include <iterator>
#include "grid.hpp"

namespace grid{

template <class Type>
class GridIterator : public std::iterator<std::random_access_iterator_tag, Type, ptrdiff_t, Type*, Type&>{
	Grid<Type> &grid_;
	unsigned int index_;
public:
	GridIterator(Grid<Type> &grid, const unsigned int index = grid.height_ * grid.width_);
};

template <class Type>
GridIterator<Type>::GridIterator(Grid<Type> &grid, const unsigned int index) : grid_(grid), index_(index){

}

}

#endif
