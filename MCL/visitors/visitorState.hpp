#ifndef VISITOR_STATE_H
#define VISITOR_STATE_H

#include "../../obecne/basic.h"

namespace mcl{

//! Particles arithmetic mean of states
template <class AdvancedParticle>
class VisitorState : public Visitor<AdvancedParticle>{
	State state_;
	unsigned int count_;
public:
	VisitorState();
	void visit(AdvancedParticle *particle);
	//! Return arithmetic mean of state
	inline State state();
	//! Return arithmetic mean of position x
	inline float x();
	//! Return arithmetic mean of position y
	inline float y();
	//! Return arithmetic mean of particles orientation
	inline float theta();
};

template <class AdvancedParticle>
VisitorState<AdvancedParticle>::VisitorState() :
count_(0){

}

template <class AdvancedParticle>
void VisitorState<AdvancedParticle>::visit(AdvancedParticle *particle){
	state_ += particle->state();
	++count_;
}

template <class AdvancedParticle>
inline State VisitorState<AdvancedParticle>::state(){
	return state_ / (double) count_;
}

template <class AdvancedParticle>
inline float VisitorState<AdvancedParticle>::x(){
	return state_.x / (double) count_;
}

template <class AdvancedParticle>
inline float VisitorState<AdvancedParticle>::y(){
	return state_.y / (double) count_;
}

template <class AdvancedParticle>
inline float VisitorState<AdvancedParticle>::theta(){
	return state_.theta / (double) count_;
}

}

#endif
