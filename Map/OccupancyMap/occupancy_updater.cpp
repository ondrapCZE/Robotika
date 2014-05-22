#include "occupancy_updater.hpp"
#include <algorithm>
#include <cmath>

using namespace std;
using namespace map::occupancy;

const float OccupancyUpdater::FREE_PROB = log(0.95/0.05);
const float OccupancyUpdater::OCCUPIED_PROB = log(0.05/0.95);

//============= public functions ===============

OccupancyUpdater::OccupancyUpdater(const Position &startPoint,
		const float &alpha, const float &distanceToWall, const float &maxRange) :
		startPoint_(startPoint), alpha_(alpha), distanceToWall_(distanceToWall),
		maxRange_(maxRange){
}

void OccupancyUpdater::updateMap(OccupancyMap &map) {
	float xStep = cos(alpha_);
	float yStep = sin(alpha_);
	// normalize steps
	float maxStep = std::max(std::abs(xStep),std::abs(yStep));
	//printf("MaxStep %f xStep %f yStep %f\n",maxStep,xStep,yStep);
	xStep = (xStep / maxStep)*map.resolution();
	yStep = (yStep / maxStep)*map.resolution();
	float distanceStep = hypot(xStep,yStep);

	float distance=0;
	float x = startPoint_.x;
	float y = startPoint_.y;
	while(distance < distanceToWall_){
		map.map(x,y) +=  FREE_PROB - map.defaultProb();

		x += xStep;
		y += yStep;
		distance+=distanceStep;
	}

	if(distance < maxRange_){
		map.map(x,y) += OCCUPIED_PROB - map.defaultProb();
	}
}
