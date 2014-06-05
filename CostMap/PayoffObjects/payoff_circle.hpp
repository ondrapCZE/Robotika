#ifndef PAYOFF_CIRCLE_H
#define PAYOFF_CIRCLE_H

#include "payoff_object.hpp"
#include "../../obecne/basic.h"

namespace costMap {

class PayoffCircle: public PayoffObject {
	Position center_;
	float radius_;
public:
	PayoffCircle(const Position center = Position(), const float radius = 1.0);
	void updatePayoffTable(Table table, const unsigned int width,
			const unsigned int height, const float resolution) override;
};

}

#endif
