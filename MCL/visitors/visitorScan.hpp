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
const float VisitorScan<AdvancedParticle, Map>::EPSILON = 1e-20; // TODO: set appropriate epsilon

template<class AdvancedParticle, class Map>
VisitorScan<AdvancedParticle, Map>::VisitorScan(const Position &point,
		const float &alpha, const sensor_msgs::LaserScan::ConstPtr& laserScan,
		const float &minAngle, const float &maxAngle, const unsigned int &step,
		const float &deviation, Map &map) :
		point_(point), alpha_(alpha), laserScan_(laserScan), minAngle_(
				basic_robotic_fce::valueInRange(minAngle, laserScan->angle_min,
						laserScan->angle_max)), maxAngle_(
				basic_robotic_fce::valueInRange(maxAngle, laserScan->angle_min,
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
	laser.position.x += point_.x * cos(state.angle)
			- point_.y * sin(state.angle);
	laser.position.y += point_.x * sin(state.angle)
			+ point_.y * cos(state.angle);
	laser.angle = basic_robotic_fce::normAngle(state.angle + alpha_);

	// TODO: use all scan or some of them
	int index = (laserScan_->angle_max - maxAngle_)
			/ laserScan_->angle_increment;
	int stopIndex = (laserScan_->angle_max - minAngle_)
			/ laserScan_->angle_increment;

	for (; index < stopIndex; index += step_) {
		float angle = laserScan_->angle_max
				- index * laserScan_->angle_increment;
// get distance to the nearest wall in beam direction
		float obstacleDistance = map_.distanceToNearestObstacle(laser.position,
				laser.angle + angle, laserScan_->range_max);
		float error = (laserScan_->ranges[index] - obstacleDistance);

// weight particle according to the error
		float weight = computeWeight(error, deviation_);
		if (weight < EPSILON)
			weight = EPSILON;
		particle->weight(particle->weight() * weight);
	}
}

}
#endif