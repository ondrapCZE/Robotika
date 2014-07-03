#include "occupancy_map.hpp"
#include <sstream>
#include <stdexcept>
#include <cmath>

using namespace std;
using namespace grid;
using namespace map;
using namespace map::occupancy;

const float OccupancyMap::IS_OCCUPIED_VALUE = log(0.75 / 0.25);
const float OccupancyMap::IS_FREE_VALUE = log(0.25 / 0.75);
const float OccupancyMap::DEFAULT_PROB = 0; // log(0.5/0.5)

//========== public functions ===========
OccupancyMap::OccupancyMap(const Size size, const float resolution) :
		size_(size), resolution_(resolution),
		grid_((size.x/resolution) + 1, (size.y/resolution) + 1,DEFAULT_PROB) {
	}

OccupancyMap::OccupancyMap(const OccupancyMap& map) :
		size_(map.size_), resolution_(map.resolution_),
		grid_(map.grid_)  {
}

OccupancyMap& OccupancyMap::operator=(const OccupancyMap& map){
	size_ = map.size_;
	resolution_ = map.resolution_;
	grid_ = map.grid_;
	return *this;
}

Interval OccupancyMap::distanceToNearestObstacle(const Position &point,
		const float &alpha, const float &maxDistance) {
	float xStep = cos(alpha);
	float yStep = sin(alpha);

	// normalize steps
	float maxStep = std::max(std::abs(xStep), std::abs(yStep));
	xStep /= maxStep;
	yStep /= maxStep;
	float distanceStep = hypot(xStep, yStep) * resolution_;

	float distance = 0;
	float x = point.x / resolution_;
	float y = point.y / resolution_;
	while (distance < maxDistance) {
		if (grid_.value(x, y) >= DEFAULT_PROB) {
			return Interval(distance - (resolution_/2.0),distance + (resolution_/2.0));
		}

		x += xStep;
		y += yStep;
		distance += distanceStep;
	}

	return Interval(maxDistance - (resolution_/2.0),maxDistance + (resolution_/2.0));
}
