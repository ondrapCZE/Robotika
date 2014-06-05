#include "payoff_circle.hpp"

using namespace costMap;

PayoffCircle::PayoffCircle(const Position center, const float radius) :
		center_(center), radius_(radius) {

}

void PayoffCircle::updatePayoffTable(Table table, const unsigned int width,
		const unsigned int height, const float resolution) { // TODO: use midpointCircle or simple circle algorithm

}
