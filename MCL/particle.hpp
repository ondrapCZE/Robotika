#ifndef PARTICLE_H
#define PARTICLE_H

namespace mcl{

class Particle{
protected:
    double weight_;
public:
    Particle(double weight = 0){ weight_ = weight; };
    void weight(double weight){ weight = weight_; };
    double weight(){ return weight_; };
};

}
#endif