/*!
	\brief 	Basic structure, class and function for robotic usage
 *	Units for position is in meters. Angle use radian.

	\author Ondrej Pilat
	\date 3/12/2012
	\version 0.1
	\note web: ondrap.cz mail: ondrap@ondrap.cz
 */

#ifndef BASIC_H
#define BASIC_H

#include <stdint.h>
#include <cmath>

struct Vector{
	double x;
	double y;
	
	Vector(double x=0, double y=0) : x(x), y(y){};
	
	Vector operator-(const Vector ob2) const{
		Vector temp(x - ob2.x, y - ob2.y);
		return temp;
	};
	
	Vector operator+(const Vector ob2) const{
		Vector temp(x + ob2.x, y + ob2.y);
		return temp;
	};
	
	Vector operator*(const float a) const{
		Vector temp(x * a, y * a);
		return temp;
	};
};

/*!
	\struct position
	\brief Position structure for robot or object in 2D world.
 */
struct Position {
	double x;
	double y;

	Position(double x = 0, double y = 0) : x(x), y(y){
	};
	
	double distance(const Position &position) const{
		return std::hypot(x - position.x, y - position.y);
	}
	
	Position operator-(const Position &ob2) const{
		Position temp(x - ob2.x, y - ob2.y);
		return temp;
	};
	
	Position operator+(const Position &ob2) const{
		Position temp(x + ob2.x, y + ob2.y);
		return temp;
	};
	
	Position operator+(const Vector &ob2) const{
		Position temp(x + ob2.x, y + ob2.y);
		return temp;
	};
	
	Position operator*(const double a) const{
		Position temp(x * a, y * a);
		return temp;
	};
	
	Position operator/(const double a) const{
		Position temp(x / a, y / a);
		return temp;
	};
};

/*!
	\struct state
	\brief State for robot. Inherit x,y from position structure.
 */
struct State{
	Position position;
	double angle;

	State(double X = 0, double Y = 0, double Angle = 0) : position(X, Y), angle(Angle) {
	};
};

struct Circle{
	Position center;
	double radius;
};

namespace basic_robotic_fce {

	//!	Function for random number witch use normal distribution.
	/*!
		\param Mu an double argument. Mu is center of normal distribution.
		\param Sigma an double argument. Sigma describe dispersion.
		\return Random number with normal distribution with center Mu and Sigma.
	 */
	//double randn_notrig(double Mu=0.0, double Sigma=1.0);

	//!	Function returns normalized input angle in range -Pi to Pi
	/*!	
		\param Angle an double argument.
		\return normalized input angle
	 */
	double normAngle(double Angle);

	double angle(const Position start,const Position end);
	
	uint8_t crc8(uint8_t crc, uint8_t data);

	template <class V> inline V valueInRange(V value, V lowerBoundary, V higherBoundary) {
		if(value < lowerBoundary){
			return lowerBoundary;
		}else{
			if(value > higherBoundary){
				return higherBoundary;
			}else{
				return value;
			}
		}
	}
	
	template <class V> inline V valueInRange(V value, V range) {
		return valueInRange(value,-range,range);
	}
}

#endif
