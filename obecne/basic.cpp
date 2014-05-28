#define _USE_MATH_DEFINES
#include <cmath>

#include "basic.h"

//basic_robotic_fce::randn_notrig(double Mu, double Sigma){
//
//}

double rob_fce::normAngle(double Angle) {
	while (Angle > M_PI)
		Angle -= 2 * M_PI;

	while (Angle < -M_PI)
		Angle += 2 * M_PI;

	return Angle;
}

double rob_fce::angle(const Position &start, const Position &end){
	return atan2(end.y - start.y, end.x - start.x);
}

// algorithm from avr lib
uint8_t rob_fce::crc8(uint8_t crc, uint8_t data) {
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

