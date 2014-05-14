#ifndef MCL_H
#define MCL_H

#include <vector>
#include <mutex>
#include <random>

namespace mcl{

template <class AdvancedParticle, class Visitor>
class Mcl{
    static const unsigned int MAX_PARTICLES;

    std::mutex mutex_;
    std::vector<AdvancedParticle> particles_;

    std::mt19937 randomGenerator_;
    std::uniform_real_distribution<double> realDistr_;

    double particlesWeightSum();
public:
    Mcl();
    void addParticle(AdvancedParticle particle);
    void visit(Visitor &visitor);
    void resample(int count);
};

template <class AdvancedParticle, class Visitor>
const unsigned int Mcl<AdvancedParticle, Visitor>::MAX_PARTICLES = 100;

// ======================== private functions =======================

template <class AdvancedParticle, class Visitor>
double Mcl<AdvancedParticle, Visitor>::particlesWeightSum(){
    double weightSum = 0;
    for (auto particle : particles_){
        weightSum += particle.weight();
    }

    return weightSum;
};

// ======================== public functions ========================

template <class AdvancedParticle, class Visitor>
Mcl<AdvancedParticle, Visitor>::Mcl()
: randomGenerator_(0)
{
    
};

template <class AdvancedParticle, class Visitor>
void Mcl<AdvancedParticle, Visitor>::addParticle(AdvancedParticle particle){
    std::lock_guard<std::mutex> lock(mutex_);
    particles_.push_back(particle);
};

template <class AdvancedParticle, class Visitor>
void Mcl<AdvancedParticle, Visitor>::visit(Visitor &visitor){
	std::lock_guard<std::mutex> lock(mutex_);
	for(int i=0; i < particles_.size(); ++i ){
		particles_[i].accept(visitor);
	}
}

template <class AdvancedParticle, class Visitor>
void Mcl<AdvancedParticle, Visitor>::resample(int count){
    std::lock_guard<std::mutex> lock(mutex_);

    double weightSum = particlesWeightSum();
    double step = weightSum / (double)particles_.size();
    double shift = step * realDistr_(randomGenerator_);
    
    double weightCount = 0;
    double weightIndex = shift;
    std::vector<AdvancedParticle> newParticles(count);
    for (auto particle : particles_){
        weightCount += particle.weight();
        particle.weight(1);
        while (weightCount >= weightIndex){
            newParticles.push_back(particle);
            weightIndex += step;
        }
    }

    particles_ = newParticles;
};

}
#endif
