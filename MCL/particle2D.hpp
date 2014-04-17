#ifndef PARTICLE_2D_H
#define PARTICLE_2D_H

#include "particle.hpp"
#include "visitor.hpp"
#include "../obecne/obecne.hpp"

namespace mcl{

	class Particle2D : public Particle {
		State state_;
	public:
		State state();
		void accept(const Visitor &visitor);
	};

}

#endif
