#include <cmath>

#include "MotorDriver/motorDriverSabertooth.hpp"
#include "DifferencialniPodvozek/mobDifferencialChassis.h"
#include "Encoder/encoderAtmel.hpp"
#include "Movement/movement.h"

int main(){		
	// Default value for Mob
	DiffChassisParam chassisParam;
	chassisParam.wheelBase = 0.233f;
	chassisParam.wheelRadius = 0.0531f;
	chassisParam.maxSpeed = 0.5f;
	chassisParam.wheelTics = 29696; // Use 10bit resolution encoder and 29:1 gearbox
	chassisParam.driver = new motorDriverSabertooth("/dev/ttyAMA0");
	chassisParam.encoder = new encoderAtmel("/dev/i2c-1", 0x30);
	
	MobDifferencialChassis mobChassis(chassisParam);
	Movement basic(&mobChassis);
	
	for (int i = 0; i < 4; ++i) {
		//printf("Move forward \n\r\n\r");
		basic.moveStraight(0.7f);
		//printf("Rotate \n\r\n\r");
		basic.rotate(M_PI_2);
	}


	//basic.moveStraight(1.0f);
	//basic.rotate(2*M_PI);

	mobChassis.stop();
	usleep(1000000);

	return 0;
}