/*!
 \brief 	Basic structure, class and function for robotic usage
 Units are in meters and rad.

 \author Ondrej Pilat
 \date 3/12/2012
 \version 0.1
 \note web: ondrap.cz mail: ondrap@ondrap.cz
 */

#ifndef BASIC_H
#define BASIC_H

#include <stdint.h>
#include <cmath>

//! Describe vector in 2D
struct Vector {
	double x;
	double y;

	Vector(double x = 0, double y = 0) :
			x(x), y(y) {
	}
	;

	Vector operator-(const Vector ob2) const {
		Vector temp(x - ob2.x, y - ob2.y);
		return temp;
	}
	;

	Vector operator+(const Vector ob2) const {
		Vector temp(x + ob2.x, y + ob2.y);
		return temp;
	}
	;

	Vector operator*(const double a) const {
		Vector temp(x * a, y * a);
		return temp;
	}
	;
};

//! Size in 2D
struct Size {
	double x;
	double y;
	Size(const double x = 0, const double y = 0) :
			x(x), y(y) {
	}
	;
};

/*!
 \struct position
 \brief Position structure for robot or object in 2D world.
 */
struct Position {
	double x;
	double y;

	Position(double x = 0, double y = 0) :
			x(x), y(y) {
	}
	;

	Position(const Position &pos) :
			x(pos.x), y(pos.y) {

	}
	;

	double distance(const Position &position) const {
		return std::hypot(x - position.x, y - position.y);
	}
	;

	double angle(const Position &position) const {
		return std::atan2(position.y - y, position.x - x);
	}
	;

	Position operator-(const Position &ob2) const {
		Position temp(x - ob2.x, y - ob2.y);
		return temp;
	}
	;

	Position operator+(const Position &ob2) const {
		Position temp(x + ob2.x, y + ob2.y);
		return temp;
	}
	;

	Position operator+(const Vector &ob2) const {
		Position temp(x + ob2.x, y + ob2.y);
		return temp;
	}
	;

	Position operator*(const double a) const {
		Position temp(x * a, y * a);
		return temp;
	}
	;

	Position operator/(const double a) const {
		Position temp(x / a, y / a);
		return temp;
	}
	;

	bool operator==(const Position& ob2) const {
		return ob2.x == x && ob2.y == y;
	}
};

/*!
 \struct state
 \brief State for robot. Inherit x,y from position structure.
 */
struct State: public Position {
	double theta;

	State(double X = 0, double Y = 0, double Angle = 0) :
			Position(X, Y), theta(Angle) {
	}
	;

	State operator-(const State &ob2) const {
		State temp(x - ob2.x, y - ob2.y, theta - ob2.theta);
		return temp;
	}
	;

	State operator+(const State &ob2) const {
		State temp(x + ob2.x, y + ob2.y, theta + ob2.theta);
		return temp;
	}
	;

	State& operator+=(const State &ob2) {
		x += ob2.x;
		y += ob2.y;
		theta += ob2.theta;
		return *this;
	}
	;

	State& operator=(const Position pos) {
		x = pos.x;
		y = pos.y;
		return *this;
	}
	;

	State operator*(const State &ob2) const {
		State temp(x * ob2.x, y * ob2.y, theta * ob2.theta);
		return temp;
	}
	;

	State operator/(const double a) const {
		State temp(x / a, y / a, theta / a);
		return temp;
	}
	;
};

//! Describe circle
struct Circle {
	Position center;
	double radius;
};

namespace rob_fce {

//!	Function returns normalized input angle in range -Pi to Pi
/*!
 \param Angle an double argument.
 \return normalized input angle in range -Pi to Pi
 */
double normAngle(double Angle);

//! Return angle between two positions
double angle(const Position &start, const Position &end);

//! Compute cyclic redundancy check
uint8_t crc8(uint8_t crc, uint8_t data);

//! Round input value in specific range.
template<class V> inline V valueInRange(V value, V lowerBoundary,
		V higherBoundary) {
	return value < lowerBoundary ? lowerBoundary :
			value > higherBoundary ? higherBoundary : value;
}

//! Round input value in specific range.
template<class V> inline V valueInRange(V value, V range) {
	return valueInRange(value, -range, range);
}
}

#endif
