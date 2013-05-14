#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "../DifferencialniPodvozek/mobDifferencialChassis.h"

class Movement{
private:
	BasicDifferencialChassis* chassis;
	State finalState;
public:
	Movement(BasicDifferencialChassis* chassis);

	void moveStraight(float meter);
	void rotate(float angle);
};

#endif
