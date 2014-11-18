#ifndef PARTICLE_2D_H
#define PARTICLE_2D_H

#include "particle.hpp"
#include "../visitors/visitor.hpp"
#include "../../obecne/basic.h"

namespace mcl{

	//! Expand basic particle with state
	class Particle2D : public Particle {
		State state_;
	public:
		//! Set particle state
		/*!
		 *  \param x particle position in x axis
		 *  \param y particle position in y axis
		 *  \param theta particle orientation
		 */
		Particle2D(const double &x = 0, const double &y = 0, const double &theta = 0);
		//! Set particle state
		void state(const State &state);
		//! Return particle state
		State state();
		//! Accept visitor
		void accept(Visitor<Particle2D> &visitor);
	};

}

#endif
