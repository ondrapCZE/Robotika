#include "mcl.hpp"

using namespace mcl;

void Mcl::addParticle(Particle& particle){
    std::lock_guard<std::mutex> lck(lock);
    particles_.push_back(particle);
}

