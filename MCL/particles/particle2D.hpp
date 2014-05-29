#ifndef PARTICLE_2D_H
#define PARTICLE_2D_H

#include "particle.hpp"
#include "../visitors/visitor.hpp"
#include "../../obecne/basic.h"

namespace mcl{

	class Particle2D : public Particle {
		State state_;
	public:
		Particle2D(const double &x = 0, const double &y = 0, const double &theta = 0);
		void state(const State &state);
		State state();
		void accept(Visitor<Particle2D> &visitor);
		void copy(const Particle2D& particle);
	};

}

#endif
