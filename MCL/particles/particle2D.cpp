#include "particle2D.hpp"

using namespace mcl;

// ================== public functions ===============

Particle2D::Particle2D(const double &x, const double &y, const double &theta) :
state_(State(x,y,theta)){

}

void Particle2D::state(const State &state){
	state_ = state;
}

State Particle2D::state(){
	return state_;
}

void Particle2D::accept(Visitor<Particle2D> &visitor){
	visitor.visit(this);
}

void Particle2D::copy(const Particle2D& particle){
	Particle::copy(particle);
	state_ = particle.state_;
}
