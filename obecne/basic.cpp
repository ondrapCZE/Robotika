#include "basic.h"
#define _USE_MATH_DEFINES
#include <cmath>

//basic_robotic_fce::randn_notrig(double Mu, double Sigma){
//
//}

float basic_robotic_fce::valueInRange(float value, float range){
	if(value < range){
		if(value > -range){
			return value;
		}else{
			return - range;
		}
	}else{
		return range;
	}
}

double basic_robotic_fce::normAngle(double Angle){
	while(Angle > M_PI)
		Angle -= 2*M_PI;

	while(Angle < -M_PI)
		Angle += 2*M_PI;

	return Angle;
}

