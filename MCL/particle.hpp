#ifndef PARTICLE_H
#define PARTICLE_H

namespace mcl{

class Particle{
protected:
    double weight_;
public:
    void weight(double weight){ weight = weight_; };
    double weight(){ return weight_; };
};

}
#endif