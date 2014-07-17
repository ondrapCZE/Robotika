#ifndef GRID_MAP_H
#define GRID_MAP_H

#include <sstream>
#include <stdexcept>

#define CHECK_BOUNDARY

#ifdef CHECK_BOUNDARY
#define TEST_BOUNDARY(X,Y,SIZE_X,SIZE_Y) \
	if(X >= SIZE_X || Y >= SIZE_Y) { \
		std::stringstream msg; \
		msg << "Out of range [" << X << "," << Y << "]"; \
		printf(msg.str().c_str()); \
		throw new std::out_of_range(msg.str());\
	}
#else
#define TEST_BOUNDARY(X,Y,SIZE_X,SIZE_Y)
#endif

namespace grid {

template<class Type> class GridIterator;

template<class Type>
class Grid {
	typedef class GridIterator<Type> Iterator;
	typedef class GridIterator<const Type> ConstIterator;

	unsigned int width_;
	unsigned int height_;

	Type* values_;

	friend Iterator;
public:
	Grid(const unsigned int width, const unsigned int height,
			const Type initialType = Type());
	// copy constructor
	Grid(const Grid& grid);
	// Assign operator
	Grid& operator=(const Grid& grid);
	~Grid();

	void setAllValues(const Type value);

	inline bool inGrid(const int &x, const int &y){
		return x >= 0 && x < width_ && y >= 0 && y < height_;
	};

	inline Type& value(const unsigned int &x, const unsigned int &y) {
		TEST_BOUNDARY(x, y, width_, height_)
		return values_[y * width_ + x];
	}
	; // in global coordinates, return Type from map
	inline unsigned int widht() {
		return width_;
	}
	;
	inline unsigned int height() {
		return height_;
	}
	;

	//return iterator
	Iterator begin();
	Iterator end();

	ConstIterator cbegin();
	ConstIterator cend();
};

template<class Type>
Grid<Type>::Grid(const unsigned int width, const unsigned int height,
		const Type initialType) :
		width_(width), height_(height) {

	values_ = new Type[width_ * height_];
	// set zero in all cells
	setAllValues(initialType);
}

template<class Type>
Grid<Type>::Grid(const Grid<Type>& grid) :
		width_(grid.width_), height_(grid.height_) {

	values_ = new Type[width_ * height_];

	for (unsigned int i = 0; i < height_ * width_; ++i) {
		values_[i] = grid.values_[i];
	}
}

template<class Type>
Grid<Type>& Grid<Type>::operator=(const Grid<Type>& grid) {
	if (width_ * height_ != grid.width_ * grid.height_) {
		delete[] values_;
		values_ = new Type[grid.width_ * grid.height_];
	}

	width_ = grid.width_;
	height_ = grid.height_;

	for (unsigned int i = 0; i < height_ * width_; ++i) {
		values_[i] = grid.values_[i];
	}

	return *this;
}

template<class Type>
Grid<Type>::~Grid() {
	delete[] values_;
}

template<class Type>
void Grid<Type>::setAllValues(const Type value) {
	for (unsigned int i = 0; i < height_ * width_; ++i) {
		values_[i] = value;
	}
}

//return iterator
template<class Type>
typename Grid<Type>::Iterator Grid<Type>::begin() {
	return GridIterator<Type>(*this, 0);
}

template<class Type>
typename Grid<Type>::Iterator Grid<Type>::end() {
	return Iterator(*this, width_ * height_);
}

template<class Type>
typename Grid<Type>::ConstIterator Grid<Type>::cbegin() {
	return ConstIterator(*this, 0);
}

template<class Type>
typename Grid<Type>::ConstIterator Grid<Type>::cend() {
	return ConstIterator(*this, width_ * height_);
}

}

#endif
