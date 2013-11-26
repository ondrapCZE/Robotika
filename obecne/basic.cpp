#include "basic.h"
#define _USE_MATH_DEFINES
#include <cmath>

//basic_robotic_fce::randn_notrig(double Mu, double Sigma){
//
//}

double basic_robotic_fce::normAngle(double Angle) {
	while (Angle > M_PI)
		Angle -= 2 * M_PI;

	while (Angle < -M_PI)
		Angle += 2 * M_PI;

	return Angle;
}

// algorithm from avr lib

uint8_t basic_robotic_fce::crc8(uint8_t crc, uint8_t data) {
	uint8_t i;

	crc = crc ^ data;
	for (i = 0; i < 8; i++) {
		if (crc & 0x01)
			crc = (crc >> 1) ^ 0x8C;
		else
			crc >>= 1;
	}

	return crc;
}

