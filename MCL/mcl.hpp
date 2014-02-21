#ifndef MCL_H
#define MCL_H

#include <vector>
#include <mutex>

#include "particle.hpp"
#include "particle_visitor.hpp"

namespace mcl{

typedef std::vector<Particle&> ParticleVector;

class Mcl{
    std::mutex lock;
    ParticleVector particles_;
public:
    void addParticle(Particle& particle);
    int adaptiveResample();
    void resample(int count);
};

}
#endif