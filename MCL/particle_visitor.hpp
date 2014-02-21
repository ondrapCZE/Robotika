#ifndef PARTICLE_VISITOR_H
#define PARTICLE_VISITOR_H

#include "particle.hpp"

class ParticleVisitor{
public:
    virtual void visit(Particle &particle) = 0;
};

#endif