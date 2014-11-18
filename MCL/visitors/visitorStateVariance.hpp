#ifndef VISITOR_STATE_VARIANCE_H
#define VISITOR_STATE_VARIANCE_H

#include "../../obecne/basic.h"
namespace mcl{

//! Particles variance of states
template <class AdvancedParticle>
class VisitorStateVariance : public Visitor<AdvancedParticle>{
	const State &state_;
	State stateVariance_;
	unsigned int count_;
public:
	//! Set arithmetic mean of particles states
	VisitorStateVariance(const State &state);
	void visit(AdvancedParticle *particle);
	//! Return states variance
	State stateVariance();
};

template <class AdvancedParticle>
VisitorStateVariance<AdvancedParticle>::VisitorStateVariance(const State &state) :
state_(state),
count_(0){

}

template <class AdvancedParticle>
void VisitorStateVariance<AdvancedParticle>::visit(AdvancedParticle *particle){
	stateVariance_ +=  (state_ - particle->state()) * (state_ - particle->state());
	++count_;
}

template <class AdvancedParticle>
State VisitorStateVariance<AdvancedParticle>::stateVariance(){
	return stateVariance_ / (double) count_;
}

}


#endif
