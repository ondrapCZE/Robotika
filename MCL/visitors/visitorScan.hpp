#ifndef VISITOR_SCAN_H
#define VISITOR_SCAN_H

#include <cmath>

namespace mcl {

template<class AdvancedParticle, class Map>
class VisitorScan: virtual public Visitor<AdvancedParticle> {
	static const float EPSILON;

	// laser scanner position according to the particle
	Position point_;
	float alpha_;

	// one beam of scanner
	float beta_;
	float distance_;
	float deviation_;
	float maxDistance_;
	// map
	Map &map_;
public:
	VisitorScan(const Position &point, const float &alpha, const float &beta,
			const float &distance, const float &deviation,
			const float &maxDistance, Map &map);
	inline double computeWeight(const double mean, const double deviation);
	void visit(AdvancedParticle *particle);
};

template<class AdvancedParticle, class Map>
const float VisitorScan<AdvancedParticle, Map>::EPSILON = 1e-20; // TODO: set appropriate epsilon

template<class AdvancedParticle, class Map>
VisitorScan<AdvancedParticle, Map>::VisitorScan(const Position &point,
		const float &alpha, const float &beta, const float &distance,
		const float &deviation, const float &maxDistance, Map &map) :
		point_(point), alpha_(alpha), beta_(beta), distance_(distance), deviation_(
				deviation), maxDistance_(maxDistance), map_(map) {

}

template<class AdvancedParticle, class Map>
inline double VisitorScan<AdvancedParticle, Map>::computeWeight(
		const double mean, const double deviation) {
return (pow(M_E, -(mean*mean)/(2*deviation)))/(sqrt(2*M_PI*deviation));
}

template<class AdvancedParticle, class Map>
void VisitorScan<AdvancedParticle, Map>::visit(AdvancedParticle *particle) {
State state = particle->state();
State laser = state;
// move particle frame in laser frame
laser.position.x += point_.x * cos(state.angle) + point_.y * sin(state.angle);
laser.position.y += -point_.x * sin(state.angle) + point_.y * cos(state.angle);
laser.angle = basic_robotic_fce::normAngle(laser.angle + alpha_);
// get distance to the nearest wall in beam direction
float obstacleDistance = map_.distanceToNearestObstacle(laser.position,
		laser.angle + beta_, maxDistance_);
float error = (distance_ - obstacleDistance);

// weight particle according to the error
float weight = computeWeight(error, deviation_);
if (weight < EPSILON)
	weight = EPSILON;
particle->weight(particle->weight() * weight);
}

}
#endif
