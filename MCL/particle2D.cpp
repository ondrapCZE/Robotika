#include "particle2D.hpp"

using namespace mcl;

// ================== public functions ===============
State Particle2D::state(){
	return state_;
}

void Particle2D::accept(Visitor<Particle2D> &visitor){
	visitor.visit(this);
}
