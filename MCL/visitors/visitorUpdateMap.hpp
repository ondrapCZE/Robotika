#ifndef VISITOR_UPDATE_MAP_H
#define VISITOR_UPDATE_MAP_H

#include "../../Map/OccupancyMap/occupancy_updater.hpp"

namespace mcl {

template<class AdvancedParticle>
class VisitorUpdateMap: public Visitor<AdvancedParticle> {
	// laser scanner relative position according to the particle
	const State laserState_;

	// scanner measurement
	const sensor_msgs::LaserScan::ConstPtr& laserScan_;

	// adjust VisitorScan weighting parameters
	const float minAngle_;
	const float maxAngle_;
public:
	VisitorUpdateMap(const State laserState,
			const sensor_msgs::LaserScan::ConstPtr& laserScan,
			const float &minAngle, const float &maxAngle);
	void visit(AdvancedParticle *particle);
};

template<class AdvancedParticle>
VisitorUpdateMap<AdvancedParticle>::VisitorUpdateMap(const State laserState,
		const sensor_msgs::LaserScan::ConstPtr& laserScan,
		const float &minAngle, const float &maxAngle) :
		laserState_(laserState), laserScan_(laserScan), minAngle_(minAngle), maxAngle_(
				maxAngle) {

}

template<class AdvancedParticle>
void VisitorUpdateMap<AdvancedParticle>::visit(AdvancedParticle *particle) {
	State state = particle->state();
	state.x += cos(state.theta) * laserState_.x
			- sin(state.theta) * laserState_.y;
	state.y += sin(state.theta) * laserState_.x
			+ cos(state.theta) * laserState_.y;
	state.theta = rob_fce::normAngle(state.theta + laserState_.theta);

	::map::occupancy::OccupancyUpdater updater(state, laserScan_, -M_PI_2,
			M_PI_2);

	particle->updateMap(updater);
}

}

#endif
