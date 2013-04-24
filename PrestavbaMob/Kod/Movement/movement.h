#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "../DifferencialniPodvozek/mobDifferencialChassis.h"

class Movement{
private:
	BasicDifferencialChassis* chassis;
	State finalState;
public:
	Movement(BasicDifferencialChassis* chassis);

	bool moveStraight(double meter);
	bool rotate(double angle);
};

#endif
