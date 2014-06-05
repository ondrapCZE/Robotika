#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "../../obecne/basic.h"

namespace costMap{

class Movement{
public:
	virtual float getPayoff(const Position &position) = 0;
};

}

#endif
