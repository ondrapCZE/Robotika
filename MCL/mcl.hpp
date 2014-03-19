#ifndef MCL_H
#define MCL_H

#include <vector>
#include <mutex>

namespace mcl{

template <class AdvancedParticle>
class Mcl{
    std::mutex mutex_;
    std::vector<AdvancedParticle*> particles_;
public:
    void addParticle(AdvancedParticle* particle);
    int adaptiveResample();
    void resample(int count);
};

template <class AdvancedParticle>
void Mcl<AdvancedParticle>::addParticle(AdvancedParticle* particle){
    std::lock_guard<std::mutex> lock(mutex_);
    particles_.push_back(particle);
};

}
#endif