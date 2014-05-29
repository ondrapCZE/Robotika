#ifndef PARTICLE_H
#define PARTICLE_H

namespace mcl{

class Particle{
    double weight_;
public:
    Particle(double weight = 1.0){ weight_ = weight; };
    void weight(const double &weight){ weight_ = weight; };
    double weight(){ return weight_; };
    void copy(const Particle& particle){ weight_ = particle.weight_;};
};

}
#endif
