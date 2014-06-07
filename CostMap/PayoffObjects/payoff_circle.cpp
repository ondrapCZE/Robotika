#include "payoff_circle.hpp"

using namespace costMap;

PayoffCircle::PayoffCircle(const Position center, const float radius, const float payoff) :
		center_(center), radius_(radius), payoff_(payoff) {

}

void PayoffCircle::updatePayoffTable(Table table, float resolution) { // TODO: use midpointCircle or simple circle algorithm

}

int PayoffCircle::getMinPayoff(){
	return payoff_;
}
