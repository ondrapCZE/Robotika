#include "occupancy_updater.hpp"
#include <algorithm>
#include <cmath>

using namespace std;
using namespace map::occupancy;

const float OccupancyUpdater::FREE_PROB = log(0.95/0.05);
const float OccupancyUpdater::OCCUPIED_PROB = log(0.05/0.95);

//============= public functions ===============

OccupancyUpdater::OccupancyUpdater(const Position &startPoint,
		const float &alpha, const float &distanceToWall) :
		startPoint_(startPoint), alpha_(alpha), distanceToWall_(distanceToWall) {
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
	//printf("Updater: stepX %f stepY %f stepDistance %f distanceToWall %f \n", xStep,yStep,distanceStep,distanceToWall_);
	while(distance < distanceToWall_){
		map.map(x,y) +=  FREE_PROB - map.defaultProb();

		x += xStep;
		y += yStep;
		distance+=distanceStep;
		//printf("Updater step [%f,%f] distance %f\n",x,y,distance);
	}

	//printf("Previous map value: %f \n" , map.map(x,y));
	map.map(x,y) += OCCUPIED_PROB - map.defaultProb();
	//printf("Updated map value: %f \n" , map.map(x,y));
}
