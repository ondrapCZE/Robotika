#include "occupancy_updater.hpp"
#include <algorithm>
#include <cmath>

using namespace std;
using namespace map::occupancy;

const float FREE_PROB = log(0.95/0.05);
const float OCCUPIED_PROB = log(0.05/0.95);

//============= public functions ===============

OccupancyUpdater::OccupancyUpdater(const Position &startPoint,
		const float &alpha, const float &distanceToWall) :
		startPoint_(startPoint), alpha_(alpha), distanceToWall_(distanceToWall) {
}

void OccupancyUpdater::updateMap(OccupancyMap &map) {
	float xStep = cos(alpha_);
	float yStep = sin(alpha_);
	// normalize steps
	float maxStep = max(xStep,yStep);
	xStep /= maxStep;
	yStep /= maxStep;
	float distanceStep = hypot(xStep,yStep)*map.resolution();

	float distance=0;
	float x = startPoint_.x;
	float y = startPoint_.y;
	while(distance < distanceToWall_){ // TODO: check map boundary
		float oldValue = map.map(x,y);
		map.map(x,y,oldValue + FREE_PROB - map.defaultProb());

		x += xStep;
		y += yStep;
		distance+=distanceStep;
	}

	float oldValue = map.map(x,y);
	map.map(x,y,oldValue + OCCUPIED_PROB - map.defaultProb());
}
