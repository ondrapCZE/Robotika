#include "cost_map.hpp"

using namespace ::costMap;
using namespace ::grid;

CostMap::CostMap(Size size, const float resolution) :
	size_(size),
	resolution_(resolution),
	costMap_((size.x/resolution) + 1, (size.y/resolution) + 1),
	payoffTable_((size.x/resolution) + 1, (size.y/resolution) + 1)
	{

}
