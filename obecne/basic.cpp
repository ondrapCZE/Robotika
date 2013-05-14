#include "basic.h"

//basic_robotic_fce::normAngle(double Angle){
//
//}

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

