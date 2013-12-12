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

	void moveCircle(float diameter, float angle, direction circleDirection, float outSpeed = 0);
	void moveStraight(float meter, float outSpeed = 0);
	void rotate(float angle, float outSpeed = 0);
};

#endif
