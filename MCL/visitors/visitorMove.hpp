#ifndef VISITOR_MOVE_H
#define VISITOR_MOVE_H

#include <random>
#include <cmath>

#include "visitor.hpp"
#include "../../obecne/basic.h"

namespace mcl {

template<class AdvancedParticle>
class VisitorMove: public Visitor<AdvancedParticle> {
	const double alpha_;
	const double distance_;
	const double beta_;

	const double alphaError_;
	const double distanceError_;
	const double betaError_;

	std::mt19937 randomGenerator_;
	std::normal_distribution<double> normDistr_;
public:
	VisitorMove(double alpha, double distance, double beta);
	VisitorMove(double alpha, double distance, double beta, double alphaError,
			double distanceError, double betaError);
	void visit(AdvancedParticle *particle);
};

template<class AdvancedParticle>
VisitorMove<AdvancedParticle>::VisitorMove(double alpha, double distance,
		double beta) :
		alpha_(alpha), distance_(distance), beta_(beta), alphaError_(
				alpha * 0.01), distanceError_(distance * 0.02), betaError_(
				beta * 0.01) {
}

template<class AdvancedParticle>
VisitorMove<AdvancedParticle>::VisitorMove(double alpha, double distance,
		double beta, double alphaError, double distanceError, double betaError) :
		alpha_(alpha), distance_(distance), beta_(beta), alphaError_(
				alphaError*alphaError), distanceError_(distanceError*distanceError), betaError_(
				betaError*betaError) {
}

template<class AdvancedParticle>
void VisitorMove<AdvancedParticle>::visit(AdvancedParticle *particle) {
	State updatedState = particle->state();

	//updatedState.angle = basic_robotic_fce::normAngle(updatedState.angle + alpha_);
	updatedState.theta = rob_fce::normAngle(
			updatedState.theta + alpha_
					+ normDistr_(randomGenerator_) * alphaError_);

	//double distanceNoised = distance_;
	double distanceNoised = distance_
			+ normDistr_(randomGenerator_) * distanceError_;
	updatedState.x += cos(updatedState.theta) * distanceNoised;
	updatedState.y += sin(updatedState.theta) * distanceNoised;

	//updatedState.angle = basic_robotic_fce::normAngle(updatedState.angle + beta_);
	updatedState.theta = rob_fce::normAngle(
			updatedState.theta + beta_
					+ normDistr_(randomGenerator_) * betaError_);

	//printf("Updated position [%f,%f,%f] \n", updatedState.position.x, updatedState.position.y, updatedState.angle);
	particle->state(updatedState);
}

}

#endif
