#ifndef VISITOR_MOVE_H
#define VISITOR_MOVE_H

#include <random>

#include "visitor.hpp"
#include "../obecne/obecne.hpp"

namespace mcl{

template <class AdvancedParticle>
class VisitorMove : public Visitor<AdvancedParticle>{
	const double alpha_;
	const double distance_;
	const double beta_;

	std::mt19937 &randomGenerator_;
	std::normal_distribution<double> normDistr_;
public:
	VisitorMove(double alpha, double distance, double beta, std::mt19937 &randomGenerator);
	void visit(AdvancedParticle &particle);
};

template <class AdvancedParticle>
VisitorMove<AdvancedParticle>::VisitorMove(double alpha, double distance, double beta, std::mt19937 &randomGenerator) :
alpha_(alpha),
distance_(distance),
beta_(beta),
randomGenerator_(randomGenerator){
}

template <class AdvancedParticle>
void VisitorMove<AdvancedParticle>::visit(AdvancedParticle &particle){
	particle.state.angle += alpha_ + normDistr_(randomGenerator_)*alpha_;
}

}

#endif
