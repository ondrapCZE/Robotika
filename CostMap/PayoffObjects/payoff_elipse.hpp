#ifndef PAYOFF_CIRCLE_H
#define PAYOFF_CIRCLE_H

#include "payoff_object.hpp"
#include "../../obecne/basic.h"

namespace costMap {

class PayoffElipse: public PayoffObject {
	Position center_;
	float radiusX_;
	float radiusY_;
	int payoff_;

	inline void setTableValue(Table table, const int x, const int y){
		if(x >= 0 && x < table.widht() && y >= 0 && y < table.height()){
			table.value(x,y) += payoff_;
		}
	}
public:
	PayoffElipse(const Position center = Position(), const float radiusX = 1.0,
			const float radiusY = 1.0, const float payoff = 10);
	void updatePayoffTable(Table table, float resolution) override;
	int getMinPayoff() override;
};

}

#endif
