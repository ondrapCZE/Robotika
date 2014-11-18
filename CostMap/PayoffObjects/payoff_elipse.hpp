#ifndef PAYOFF_CIRCLE_H
#define PAYOFF_CIRCLE_H

#include "payoff_object.hpp"
#include "../../obecne/basic.h"

namespace costMap {

//! Ellipse payoff object
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
	//! It defines payoff object as ellipse.
	/*!	\param center position of the ellipse center
	 * 	\param radiusX size of the ellipse x axis radius
	 * 	\param radiusY size of the ellipse y axis radius
	 * 	\param payoff value which will be added to all payoff function cells covered with this ellipse
	 */
	PayoffElipse(const Position center = Position(), const float radiusX = 1.0,
			const float radiusY = 1.0, const float payoff = 10);
	//! Add payoff value to all payoff function cells coverd with this ellipse
	/*! \param table payoff function array
	 * 	\param resolution payoff function resolution
	 */
	void updatePayoffTable(Table table, float resolution) override;
	int getMinPayoff() override;
};

}

#endif
