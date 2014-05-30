#ifndef MCL_H
#define MCL_H

#include <vector>
#include <forward_list>
#include <list>
#include <memory>
#include <mutex>
#include <random>

namespace mcl {

template<class AdvancedParticle, class Visitor>
class Mcl {
public:
	typedef std::shared_ptr<AdvancedParticle> ParticlePtr;

	Mcl();
	void addParticle(ParticlePtr particle);
	void visit(Visitor &visitor);
	void resample(int count = -1);
private:
	typedef std::forward_list<ParticlePtr> List;
	typedef std::list<ParticlePtr> Container;

	static const unsigned int MAX_PARTICLES;

	std::mutex mutex_;
	List unusedParticles_;
	Container particles_;

	std::mt19937 randomGenerator_;
	std::uniform_real_distribution<double> realDistr_;

	ParticlePtr getParticleCopy(ParticlePtr particle);
	double particlesWeightSum();

};

template<class AdvancedParticle, class Visitor>
const unsigned int Mcl<AdvancedParticle, Visitor>::MAX_PARTICLES = 100;

// ======================== private functions =======================
template<class AdvancedParticle, class Visitor>
typename Mcl<AdvancedParticle, Visitor>::ParticlePtr Mcl<AdvancedParticle,
		Visitor>::getParticleCopy(
		Mcl<AdvancedParticle, Visitor>::ParticlePtr particle) {
	ParticlePtr copiedParticle;
	if (!unusedParticles_.empty()) { // we have some old particles which we can reuse
		copiedParticle = unusedParticles_.front();
		copiedParticle->copy(*particle);
		unusedParticles_.pop_front();
	} else { // We have to allocate new particle
		copiedParticle = ParticlePtr(new AdvancedParticle(*particle));
	}
	return copiedParticle;
}

template<class AdvancedParticle, class Visitor>
double Mcl<AdvancedParticle, Visitor>::particlesWeightSum() {
	double weightSum = 0;
	for (auto particle : particles_) {
		weightSum += particle->weight();
	}

	return weightSum;
}
;

// ======================== public functions ========================

template<class AdvancedParticle, class Visitor>
Mcl<AdvancedParticle, Visitor>::Mcl() :
		randomGenerator_(0) {

}
;

template<class AdvancedParticle, class Visitor>
void Mcl<AdvancedParticle, Visitor>::addParticle(ParticlePtr particle) {
	std::lock_guard < std::mutex > lock(mutex_);
	particles_.push_back(particle);
}
;

template<class AdvancedParticle, class Visitor>
void Mcl<AdvancedParticle, Visitor>::visit(Visitor &visitor) {
	std::lock_guard < std::mutex > lock(mutex_);
	for (auto particle : particles_) {
		particle->accept(visitor);
	}
}

template<class AdvancedParticle, class Visitor>
void Mcl<AdvancedParticle, Visitor>::resample(int count) {
	std::lock_guard < std::mutex > lock(mutex_);
	if (count == -1) {
		count = particles_.size();
	}

	double weightSum = particlesWeightSum();
	double step = weightSum / (double) count;
	double shift = step * realDistr_(randomGenerator_);

	double weightCount = 0;
	double weightIndex = shift;

	Container newParticles;
	while(!particles_.empty()) {
		bool used = false;
		ParticlePtr particle = particles_.front();

		weightCount += particle->weight();
		//printf("Particle weight %f\n", particle->weight());
		particle->weight(1);
		while (weightCount >= weightIndex) {
			if(!used){
				newParticles.push_back(particle);
				used = true;
			}else{
				newParticles.push_back(getParticleCopy(particle));
			}
			weightIndex += step;
		}

		if(!used){
			unusedParticles_.push_front(particle);
		}

		particles_.pop_front();
	}

	particles_ = newParticles;
}
;

}
#endif
