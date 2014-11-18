#ifndef VISITOR_BEST_H
#define VISITOR_BEST_H

#include "visitor.hpp"

namespace mcl{

//! Find best particle and make its copy
template <class AdvancedParticle>
class VisitorBest : public Visitor<AdvancedParticle>{
	AdvancedParticle particle_;
public:
	//! Initialize particle weight
	VisitorBest(){ particle_.weight(0) ;};

	//! Return best particle
	AdvancedParticle& particle(){ return particle_; };
	void visit(AdvancedParticle *particle);
};

template <class AdvancedParticle>
void VisitorBest<AdvancedParticle>::visit(AdvancedParticle* particle){
	if(particle_.weight() < particle->weight()){
		particle_ = *particle;
	}
}

}
#endif
