#ifndef VISITOR_SCAN_H
#define VISITOR_SCAN_H

#include <cmath>
#include <sensor_msgs/LaserScan.h>

namespace mcl {

template<class AdvancedParticle, class Map>
class VisitorScan: virtual public Visitor<AdvancedParticle> {
	static const float EPSILON;

	// laser scanner relative position according to the particle
	const Position point_;
	const float alpha_;

	// scanner measurement
	const sensor_msgs::LaserScan::ConstPtr& laserScan_;
	const float deviation_;

	// adjust VisitorScan weighting parameters
	const float minAngle_;
	const float maxAngle_;
	const unsigned int step_;

	// map
	Map &map_;
public:
	VisitorScan(const Position &point, const float &alpha,
			const sensor_msgs::LaserScan::ConstPtr& laserScan,
			const float &minAngle, const float &maxAngle,
			const unsigned int &step, const float &deviation, Map &map);
	inline double computeWeight(const double mean, const double deviation);
	void visit(AdvancedParticle *particle);
};

template<class AdvancedParticle, class Map>
const float VisitorScan<AdvancedParticle, Map>::EPSILON = 1e-40; // TODO: set appropriate epsilon

template<class AdvancedParticle, class Map>
VisitorScan<AdvancedParticle, Map>::VisitorScan(const Position &point,
		const float &alpha, const sensor_msgs::LaserScan::ConstPtr& laserScan,
		const float &minAngle, const float &maxAngle, const unsigned int &step,
		const float &deviation, Map &map) :
		point_(point), alpha_(alpha), laserScan_(laserScan), minAngle_(
				rob_fce::valueInRange(minAngle, laserScan->angle_min,
						laserScan->angle_max)), maxAngle_(
				rob_fce::valueInRange(maxAngle, laserScan->angle_min,
						laserScan->angle_max)), step_(step), deviation_(
				deviation), map_(map) {

}

template<class AdvancedParticle, class Map>
inline double VisitorScan<AdvancedParticle, Map>::computeWeight(
		const double mean, const double deviation) {
	return (pow(M_E, -(mean * mean) / (2 * deviation)))
			/ (sqrt(2 * M_PI * deviation));
}

template<class AdvancedParticle, class Map>
void VisitorScan<AdvancedParticle, Map>::visit(AdvancedParticle *particle) {
	const State& state = particle->state();
	State laser = state;
// move particle frame in laser frame
	laser.x += point_.x * cos(state.theta)
			- point_.y * sin(state.theta);
	laser.y += point_.x * sin(state.theta)
			+ point_.y * cos(state.theta);
	laser.theta = rob_fce::normAngle(state.theta + alpha_);

	int index = (laserScan_->angle_max - maxAngle_)
			/ laserScan_->angle_increment;
	int stopIndex = (laserScan_->angle_max - minAngle_)
			/ laserScan_->angle_increment;

	for (; index < stopIndex; index += step_) {
		float angle = laserScan_->angle_max
				- index * laserScan_->angle_increment;
// get distance to the nearest wall in beam direction
		float obstacleDistance = map_.distanceToNearestObstacle(laser,
				laser.theta + angle, laserScan_->range_max);
		float error = (laserScan_->ranges[index] - obstacleDistance);

// weight particle according to the error
		float weight = computeWeight(error, deviation_);
		particle->weight(particle->weight() * weight);

		if (particle->weight() < EPSILON)
			particle->weight(EPSILON);
	}
}

}
#endif
