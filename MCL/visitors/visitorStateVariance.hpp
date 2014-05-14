#ifndef VISITOR_STATE_VARIANCE_H
#define VISITOR_STATE_VARIANCE_H

namespace mcl{

#include "../obecne/basic.h"

namespace mcl{

template <class AdvancedParticle>
class VisitorStateVariance : public Visitor<AdvancedParticle>{
	const State &state_;
	State stateVariance_;
	unsigned int count_;
public:
	VisitorStateVariance(const State &state);
	void visit(AdvancedParticle *particle);
	State stateVariance();
};

template <class AdvancedParticle>
VisitorStateVariance<AdvancedParticle>::VisitorStateVariance(const State &state) :
state_(state),
count_(0){

}

template <class AdvancedParticle>
void VisitorStateVariance<AdvancedParticle>::visit(AdvancedParticle *particle){
	stateVariance_ +=  (state - particle->state()) * (state - particle->state());
	++count_;
}

template <class AdvancedParticle>
State VisitorStateVariance<AdvancedParticle>::stateVariance(){
	return stateVariance_ / (double) count;
}

}


#endif
