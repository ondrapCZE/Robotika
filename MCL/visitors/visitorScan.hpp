#ifndef VISITOR_SCAN_H
#define VISITOR_SCAN_H

#include <cmath>
#include <sensor_msgs/LaserScan.h>
#include "../../Map/map_interface.hpp"

namespace mcl {

//! Adjust particle weight according to laser scan data and particle map
template<class AdvancedParticle, class Map>
class VisitorScan: virtual public Visitor<AdvancedParticle> {
	static const double EPSILON;

	// laser scanner relative position according to the particle
	const State relativeState_;

	// scanner measurement
	const sensor_msgs::LaserScan::ConstPtr& laserScan_;
	const float deviation_;

	// adjust VisitorScan weighting parameters
	const float minAngle_;
	const float maxAngle_;
	const float maxRange_;
	const unsigned int step_;
	const unsigned int shift_;

public:
	//! Set laser scan parameter
	/*! \param state relative position of scan center due to robot center
	 *  \param laserScan ROS message containing laser scan measurements
	 *  \param minAngle minimal angle of an useful measurement
	 *  \param maxAngle maximal angle of an useful measurement
	 *  \param deviation measurement data deviation
	 *  \param step decide which every step-th measurement use
	 *  \param maxRange adjust measurement max range (use if real max range is differ from documentation)
	 *  \param shift use every (step-th + shift) measurement
	 */
	VisitorScan(const State &state,
			const sensor_msgs::LaserScan::ConstPtr& laserScan,
			const float &minAngle, const float &maxAngle,
			const float &deviation, const unsigned int &step,
			const float maxRange = -1, const unsigned int shift = 0);
	inline double computeWeight(const double mean, const double variance);
	void visit(AdvancedParticle *particle);
};

template<class AdvancedParticle, class Map>
const double VisitorScan<AdvancedParticle, Map>::EPSILON = 1e-200;

template<class AdvancedParticle, class Map>
VisitorScan<AdvancedParticle, Map>::VisitorScan(const State &state,
		const sensor_msgs::LaserScan::ConstPtr& laserScan,
		const float &minAngle, const float &maxAngle, const float &deviation,
		const unsigned int &step, const float maxRange,
		const unsigned int shift) :
		relativeState_(state), laserScan_(laserScan), minAngle_(
				rob_fce::valueInRange(minAngle, laserScan->angle_min,
						laserScan->angle_max)), maxAngle_(
				rob_fce::valueInRange(maxAngle, laserScan->angle_min,
						laserScan->angle_max)), deviation_(deviation), step_(
				step), maxRange_(
				maxRange < 0 || maxRange > laserScan->range_max ?
						laserScan->range_max : maxRange), shift_(shift) {

}

template<class AdvancedParticle, class Map>
inline double VisitorScan<AdvancedParticle, Map>::computeWeight(
		const double mean, const double variance) {
	return (pow(M_E, -(mean * mean) / (2 * variance)))
			/ (sqrt(2 * M_PI * variance));
}

template<class AdvancedParticle, class Map>
void VisitorScan<AdvancedParticle, Map>::visit(AdvancedParticle *particle) {
	State state = particle->state();
// move particle frame in laser frame
	state.x += relativeState_.x * cos(state.theta)
			- relativeState_.y * sin(state.theta);
	state.y += relativeState_.x * sin(state.theta)
			+ relativeState_.y * cos(state.theta);
	state.theta = rob_fce::normAngle(state.theta + relativeState_.theta);

	int index = (laserScan_->angle_max - maxAngle_)
			/ laserScan_->angle_increment;
	int stopIndex = (laserScan_->angle_max - minAngle_)
			/ laserScan_->angle_increment;

	for (index += shift_; index < stopIndex; index += step_) {
		if(laserScan_->ranges[index] < 1e-5){ // cannot receive beam
			continue;
		}

		float angle = laserScan_->angle_max
				- index * laserScan_->angle_increment;
// get distance to the nearest wall in beam direction
		map::Interval obstacleDistance =
				particle->map().distanceToNearestObstacle(state,
						state.theta + angle, maxRange_);

		if (obstacleDistance.begin < 0) { // we cannot get some distance
			continue;
		}

		float error = 0;
		if (laserScan_->ranges[index] < obstacleDistance.begin
				|| laserScan_->ranges[index] > obstacleDistance.end) {
			error = laserScan_->ranges[index]
					- ((obstacleDistance.begin + obstacleDistance.end) / 2.0);
		}

// weight particle according to the error
		double weight = computeWeight(error, deviation_);
		particle->weight(particle->weight() * weight);

		if (particle->weight() < EPSILON)
			particle->weight(EPSILON);
	}
}

}
#endif
