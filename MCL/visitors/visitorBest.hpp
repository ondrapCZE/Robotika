#ifndef VISITOR_BEST_H
#define VISITOR_BEST_H

#include "visitor.hpp"

namespace mcl{

template <class AdvancedParticle>
class VisitorBest : public Visitor<AdvancedParticle>{
	AdvancedParticle particle_;
public:
	VisitorBest(){ particle_.weight(0) ;};

	AdvancedParticle& particle(){ return particle_; };
	void visit(AdvancedParticle *particle);
};

template <class AdvancedParticle>
void VisitorBest<AdvancedParticle>::visit(AdvancedParticle* particle){
	if(particle_.weight() < particle->weight()){
		particle_.copy(*particle);
	}
}

}
#endif
