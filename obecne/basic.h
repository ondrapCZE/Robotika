/*!
	\brief 	Basic structur, class and function for robotic usage
	*	Units for position is in meters. Angle use radian.

	\author Ondrej Pilat
	\date 3/12/2012
	\version 0.1
	\note web: ondrap.cz mail: ondrap@ondrap.cz
*/

#ifndef BASIC_H
#define BASIC_H

/*!
	\struct position
	\brief Position structure for robot or object in 2D world.
*/
struct Position{
	double x;
	double y;

	Position(double X = 0, double Y = 0){x = X; y = Y;};
};

/*!
	\struct state
	\brief State for robot. Inherit x,y from position structure.
*/
struct State : public Position {
	double angle;

	State(double X = 0, double Y = 0, double Angle = 0) : Position(X,Y), angle(Angle){};
};

namespace basic_robotic_fce{
	//!	Function returns normalized input angle in range -Pi to Pi
	/*!	
		\param Angle an double argument.
		\return normalized input angle
	*/
	double normAngle(double Angle);
	//!	Function for random number witch use normal distribution.
	/*!
		\param Mu an double argument. Mu is center of normal distribution.
		\param Sigma an double argument. Sigma describe dispersion.
		\return Random number with normal distribution with center Mu and Sigma.
	*/
	double randn_notrig(double Mu=0.0, double Sigma=1.0);
}

#endif
