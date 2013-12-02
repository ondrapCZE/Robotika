#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "../DifferencialniPodvozek/mobDifferencialChassis.h"

enum direction{
	LEFT,
	RIGHT
};

class Movement {
private:
	BasicDifferencialChassis* chassis;
	State finalState;
public:
	Movement(BasicDifferencialChassis* chassis);

	void moveCircle(float diameter, float angle, direction circleDirection);
	void moveStraight(float meter);
	void rotate(float angle);
};

#endif
