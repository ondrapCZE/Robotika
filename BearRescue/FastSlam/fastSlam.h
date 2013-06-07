#ifndef FASTSLAM_H
#define FASTSLAM_H

#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <cmath>

#include "vectorMap.h"
#include "../../obecne/basic.h"

#define NUM_SAMPLE 270

struct particle_STR{
	State state;

	double weight;
	
	particle_STR(State State = State(), double Weight = 1) : state(State), weight(Weight) {};
};

class FastSLAM_CLASS{
	std::vector<struct particle_STR> particles;
	
	vm::VectorMap vectorMap;

	State lastState;
	State probState;

	double weightSlow;

	void init(int Count);
	double normAngle(double Angle);
	double randn_notrig(double mu=0.0, double sigma=1.0);
	double gausianDistribution(double Diference, double Dispersion);
	void move(double Alpha = 0.0, double AlphaVar = 0.0, double Length = 0.0, double LengthVar = 0.0, double Beta = 0.0, double BetaVar = 0.0);
	State calculateMostProbabilisticState();
public:
	FastSLAM_CLASS();
	vm::VectorMap* getVectorMap(){return &vectorMap;};
	const std::vector<struct particle_STR> getParticles(){return particles;};
	void move(State State);
	void weightParticlesFromSick(std::vector<double> data);
	double resample(int Count);
	State getMostProbabilisticState();	
};

#endif