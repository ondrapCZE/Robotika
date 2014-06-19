#include "occupancy_updater.hpp"
#include <algorithm>
#include <cmath>

using namespace std;
using namespace ::map::occupancy;

const float OccupancyUpdater::FREE_PROB = log(0.05 / 0.95);
const float OccupancyUpdater::OCCUPIED_PROB = log(0.95 / 0.05);

//============= public functions ===============

OccupancyUpdater::OccupancyUpdater(const State &state,
		const sensor_msgs::LaserScan::ConstPtr& laserScan,
		const float &minAngle, const float &maxAngle) :
		laserScan_(laserScan), state_(state), minAngle_(minAngle), maxAngle_(
				maxAngle) {
}

void OccupancyUpdater::oneScanUpdate(OccupancyMap &map,
		const float &distanceToWall, const float &alpha) {
	float xStep = cos(alpha);
	float yStep = sin(alpha);
	// normalize steps
	float maxStep = std::max(std::abs(xStep), std::abs(yStep));
	//printf("MaxStep %f xStep %f yStep %f\n",maxStep,xStep,yStep);
	xStep = (xStep / maxStep) * map.resolution();
	yStep = (yStep / maxStep) * map.resolution();
	float distanceStep = hypot(xStep, yStep);

	float distance = 0;
	float x = state_.x;
	float y = state_.y;
	while (distance < distanceToWall) {
		map.map(x, y) += FREE_PROB - map.defaultProb();

		x += xStep;
		y += yStep;
		distance += distanceStep;
	}

	if (distance < laserScan_->range_max) {
		map.map(x, y) += OCCUPIED_PROB - map.defaultProb();
	}
}

void OccupancyUpdater::update(OccupancyMap &map) {
	int index = (laserScan_->angle_max - maxAngle_)
			/ laserScan_->angle_increment;
	int stopIndex = (laserScan_->angle_max - minAngle_)
			/ laserScan_->angle_increment;

	for (; index < stopIndex; ++index) {
		float angle = laserScan_->angle_max
				- index * laserScan_->angle_increment;
		oneScanUpdate(map, laserScan_->ranges[index], angle + state_.theta);
	}
}
