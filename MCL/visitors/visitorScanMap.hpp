#ifndef VISITOR_SCAN_H
#define VISITOR_SCAN_H

#include <cmath>
#include <sensor_msgs/LaserScan.h>

namespace mcl {

//! Adjust particle weight according to laser scan data and general map
template<class AdvancedParticle, class Map>
class VisitorScanMap: virtual public Visitor<AdvancedParticle> {
	static const float EPSILON;

	// laser scanner relative position according to the particle
	const State relativeScan_;

	// scanner measurement
	const sensor_msgs::LaserScan::ConstPtr& laserScan_;
	const float deviation_;

	// adjust VisitorScan weighting parameters
	const float minAngle_;
	const float maxAngle_;
	const unsigned int step_;

	// general map
	Map &map_;

	inline double computeWeight(const double mean, const double deviation);
public:
	//! Set laser scan parameter
	/*! \param relativeScan relative position of scan center due to robot center
	 *  \param laserScan ROS message containing laser scan measurements
	 *  \param minAngle minimal angle of an useful measurement
	 *  \param maxAngle maximal angle of an useful measurement
	 *  \param step decide which every step-th measurement use
	 *  \param deviation measurement data deviation
	 *  \param map general map used for particle weighting
	 */
	VisitorScanMap(const State &relativeScan,
			const sensor_msgs::LaserScan::ConstPtr& laserScan,
			const float &minAngle, const float &maxAngle,
			const unsigned int &step, const float &deviation, Map &map);
	void visit(AdvancedParticle *particle);
};

template<class AdvancedParticle, class Map>
const float VisitorScanMap<AdvancedParticle, Map>::EPSILON = 1e-40;

template<class AdvancedParticle, class Map>
VisitorScanMap<AdvancedParticle, Map>::VisitorScanMap(const State &relativeScan,
		const sensor_msgs::LaserScan::ConstPtr& laserScan,
		const float &minAngle, const float &maxAngle, const unsigned int &step,
		const float &deviation, Map &map) :
		relativeScan_(relativeScan), laserScan_(laserScan), minAngle_(
				rob_fce::valueInRange(minAngle, laserScan->angle_min,
						laserScan->angle_max)), maxAngle_(
				rob_fce::valueInRange(maxAngle, laserScan->angle_min,
						laserScan->angle_max)), step_(step), deviation_(
				deviation), map_(map) {

}

template<class AdvancedParticle, class Map>
inline double VisitorScanMap<AdvancedParticle, Map>::computeWeight(
		const double mean, const double deviation) {
	return (pow(M_E, -(mean * mean) / (2 * deviation)))
			/ (sqrt(2 * M_PI * deviation));
}

template<class AdvancedParticle, class Map>
void VisitorScanMap<AdvancedParticle, Map>::visit(AdvancedParticle *particle) {
	State state = particle->state();
// move particle frame in laser frame
	state.x += point_.x * cos(state.theta) - point_.y * sin(state.theta);
	state.y += point_.x * sin(state.theta) + point_.y * cos(state.theta);
	state.theta = rob_fce::normAngle(state.theta + alpha_);

	int index = (laserScan_->angle_max - maxAngle_)
			/ laserScan_->angle_increment;
	int stopIndex = (laserScan_->angle_max - minAngle_)
			/ laserScan_->angle_increment;

	for (; index < stopIndex; index += step_) {
		float angle = laserScan_->angle_max
				- index * laserScan_->angle_increment;
// get distance to the nearest wall in beam direction
		float obstacleDistance = map_.distanceToNearestObstacle(state,
				state.theta + angle, laserScan_->range_max);
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
