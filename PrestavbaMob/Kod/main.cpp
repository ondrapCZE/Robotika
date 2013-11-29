#include <cmath>

#include "MotorDriver/motorDriverSabertooth.hpp"
#include "DifferencialniPodvozek/mobDifferencialChassis.h"
#include "Encoder/encoderAtmel.hpp"

int main() {
	motorDriver* driver = new motorDriverSabertooth("/dev/ttyAMA0");
	encoderReader* encoderReader = new encoderAtmel("/dev/i2c-1", 0x30);
	MobDifferencialChassis mobChassis(encoderReader, driver);
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