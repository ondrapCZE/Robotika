#ifndef FASTSLAM_H
#define FASTSLAM_H

#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <cmath>

#include "vectorMap.h"

#define NUM_SAMPLE 270

struct position_STR{
	double x;
	double y;

	void move(double Length, double Angle){x += Length*cos(Angle); y += Length*sin(Angle);}
	position_STR(double X = 0, double Y = 0){x = X; y = Y;};
};

struct state_STR{
	struct position_STR position;
	double angle;
	
	state_STR(position_STR Position = position_STR(), double Angle = 0) : angle(Angle), position(Position){};
};

struct particle_STR{
	struct state_STR state;

	double weight;
	
	particle_STR(state_STR State = state_STR(), double Weight = 1) : state(State), weight(Weight) {};
};

class FastSLAM_CLASS{
	std::vector<struct particle_STR> particles;
	
	vm::VectorMap vectorMap;

	state_STR lastState;
	state_STR probState;

	double weightSlow;

	double normAngle(double Angle);
	double randn_notrig(double mu=0.0, double sigma=1.0);
	double gausianDistribution(double Diference, double Dispersion);
	void move(double Alpha = 0.0, double AlphaVar = 0.0, double Length = 0.0, double LengthVar = 0.0, double Beta = 0.0, double BetaVar = 0.0);
	void weightParticlesFromSick(state_STR RelativeSickState, double IntervalAngle, double StartAngle,double MaxScanLength, double* Data, int Length);
	state_STR calculateMostProbabilisticState();
public:
	FastSLAM_CLASS();
	vm::VectorMap* getVectorMap(){return &vectorMap;};
	const std::vector<struct particle_STR> getParticles(){return particles;};
	void init(int Count);
	void move(state_STR State);
	double resample(int Count);
	state_STR getMostProbabilisticState();	
	void dataFromSick(state_STR RelativeSickState, double IntervalAngle, double StartAngle , double MaxScanLength ,double* Data, int Length);
};

#endif