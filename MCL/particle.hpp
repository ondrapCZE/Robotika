#ifndef PARTICLE_H
#define PARTICLE_H

class Particle{
protected:
    double weight_;
public:
    virtual void accept(class ParticleVisitor &particleVisitor) = 0;
    void weight(double weight){ weight = weight_ };
    double weight(){ return weight_; };
};

#endif