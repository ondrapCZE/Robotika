#include <cmath>
#include <iostream>

#include "PrestavbaMob/Kod/MotorDriver/sabertooth/motorDriverSabertooth.hpp"
#include "PrestavbaMob/Kod/DifferencialniPodvozek/mobDifferencialChassis.h"
#include "PrestavbaMob/Kod/Encoder/encoderAtmel.hpp"
#include "Display/display.h"
#include "PrestavbaMob/Kod/Movement/hermit/checkpointMovementHermit.hpp"

int main(){
	// Init display 
	Display display("/dev/i2c-1");	
	display.init();
	display.writeText("Start program");
	
	// Default value for Mob
	DiffChassisParam chassisParam;
	chassisParam.wheelbase = 0.2335f;
	chassisParam.wheelRadius = 0.0531f;
	chassisParam.maxSpeed = 0.5f;
	chassisParam.wheelTics = 29696; // Use 10bit resolution encoder and 29:1 gearbox
	chassisParam.driver = new motorDriverSabertooth("/dev/ttyAMA0");
	chassisParam.encoder = new encoderAtmel("/dev/i2c-1", 0x30);
	
	MobDifferentialChassis mobChassis(chassisParam);
	//Movement basic(&mobChassis);

	checkpointMovementHermit basic(&mobChassis);
	
	basic.addCheckpoint(Checkpoint(Position(1,0)));
	basic.addCheckpoint(Checkpoint(Position(1,1)));
        basic.addCheckpoint(Checkpoint(Position(0.5,2)));
        basic.addCheckpoint(Checkpoint(Position(0,1)));
	basic.addCheckpoint(Checkpoint(Position(1,1)));
        basic.addCheckpoint(Checkpoint(Position(0,0)));
        basic.addCheckpoint(Checkpoint(Position(0,1)));
        basic.addCheckpoint(Checkpoint(Position(1,0)));
	//basic.addCheckpoint(Checkpoint(Position(0.5f,0.5f)));
	//basic.addCheckpoint(Checkpoint(Position(0,0)));

	/*
	for (int i = 0; i < 4; ++i) {
		//printf("Move forward \n\r\n\r");
		display.clearDisplay();
		display.writeText("Move straight");
		basic.moveStraight(1.0f);
		//printf("Rotate \n\r\n\r");
		display.clearDisplay();
		display.writeText("Rotate");
		basic.rotate(M_PI_2);
	}*/
	
	
	//basic.moveStraight(1.0f);
	//basic.rotate(2*M_PI);
	
	//mobChassis.stop();
	std::this_thread::sleep_for(std::chrono::seconds(2000));
	return 0;
}
