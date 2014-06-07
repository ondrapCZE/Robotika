#ifndef PAYOFF_CIRCLE_H
#define PAYOFF_CIRCLE_H

#include "payoff_object.hpp"
#include "../../obecne/basic.h"

namespace costMap {

class PayoffCircle: public PayoffObject {
	Position center_;
	float radius_;
	int payoff_;
public:
	PayoffCircle(const Position center = Position(), const float radius = 1.0, const float payoff = 10);
	void updatePayoffTable(Table table, float resolution) override;
	int getMinPayoff() override;
};

}

#endif
