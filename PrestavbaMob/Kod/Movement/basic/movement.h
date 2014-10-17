#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "../../DifferencialniPodvozek/mobDifferencialChassis.h"

enum direction{
	LEFT,
	RIGHT
};

class Movement {
private:
	BasicDifferentialChassis* chassis;
	State finalState;
public:
	Movement(BasicDifferentialChassis* chassis);

	void moveCircle(const double &diameter, const double &angle, 
	const direction &circleDirection);
	
	void moveStraight(const double &meter);
	void rotate(const double &angle);
};

#endif
