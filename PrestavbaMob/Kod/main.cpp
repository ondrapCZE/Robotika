#include <cmath>

#include "MotorDriver/motorDriverSabertooth.hpp"
#include "DifferencialniPodvozek/mobDifferencialChassis.h"
#include "Encoder/encoderAtmel.hpp"
#include "Movement/movement.h"
#include "../../Display/display.h"

int main(){
	// Init display 
	Display display("/dev/i2c-1");	
	display.init();
	display.writeText("Start move");
	
	// Default value for Mob
	DiffChassisParam chassisParam;
	chassisParam.wheelbase = 0.2335f;
	chassisParam.wheelRadius = 0.0531f;
	chassisParam.maxSpeed = 0.45f;
	chassisParam.wheelTics = 29696; // Use 10bit resolution encoder and 29:1 gearbox
	chassisParam.driver = new motorDriverSabertooth("/dev/ttyAMA0");
	chassisParam.encoder = new encoderAtmel("/dev/i2c-1", 0x30);
	
	MobDifferencialChassis mobChassis(chassisParam);
	Movement basic(&mobChassis);
	/*
	for(float diameter = 1.0; diameter >= -0.001f; diameter -= 0.1f){
		basic.moveCircle(diameter,2*M_PI,RIGHT);
	}
	*/
	
	for (int i = 0; i < 4; ++i) {
		//printf("Move forward \n\r\n\r");
		display.clearDisplay();
		display.writeText("Move straight");
		basic.moveStraight(0.7f);
		//printf("Rotate \n\r\n\r");
		display.clearDisplay();
		display.writeText("Rotate");
		basic.rotate(M_PI_2);
	}
	

	//basic.moveStraight(1.0f);
	//basic.rotate(2*M_PI);

	mobChassis.stop();
	usleep(1000000);

	return 0;
}