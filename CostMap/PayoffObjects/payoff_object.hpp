#ifndef PAYOFF_OBJECT_H
#define PAYOFF_OBJECT_H

namespace costMap{

typedef float* Table;

class PayoffObject{
public:
	virtual void updatePayoffTable(Table table, const unsigned int width, const unsigned int height, const float resolution) = 0;
};

}

#endif
