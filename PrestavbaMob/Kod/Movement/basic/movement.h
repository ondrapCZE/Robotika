#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "../DifferencialniPodvozek/mobDifferencialChassis.h"

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

	void moveCircle(const float &diameter, const float &angle, 
	const direction &circleDirection);
	
	void moveStraight(const float &meter);
	void rotate(const float &angle);
};

#endif