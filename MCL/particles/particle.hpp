#ifndef PARTICLE_H
#define PARTICLE_H

namespace mcl{

// Basic particle for the MCL algorithm
class Particle{
    double weight_;
public:
    //! Set particle default weight
    Particle(double weight = 1.0){ weight_ = weight; };
    //! Virtual destructor can be overwritten in derived class
    virtual ~Particle(){};
    //! Set particle weight
    void weight(const double &weight){ weight_ = weight; };
    //! Return particle weight
    double weight(){ return weight_; };
};

}
#endif
