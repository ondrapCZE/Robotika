#ifndef VISITOR_STATE_H
#define VISITOR_STATE_H

#include "../obecne/basic.h"

namespace mcl{

template <class AdvancedParticle>
class VisitorState : public Visitor<AdvancedParticle>{
	State state_;
	unsigned int count_;
public:
	VisitorState();
	void visit(AdvancedParticle *particle);
	State state();
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
State VisitorState<AdvancedParticle>::state(){
	return state_ / (double) count;
}

}

#endif
