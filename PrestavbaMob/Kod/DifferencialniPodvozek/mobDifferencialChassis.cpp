#include "mobDifferencialChassis.h"

#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>


MobDifferencialChassis::MobDifferencialChassis(std::string I2CName, int decoderAddress, int motorsAddress, DifferencialChassisParameters chassisParam)
 : decoderAddress(decoderAddress), motorsAddress(motorsAddress), chassisParam(chassisParam){
	// Open I2C bus for read and write operation
	if((file = open(I2CName.c_str(),O_RDWR)) < 0){
		printf("Failed to open bus");
		exit(1);
	}
	
}

// Acquire bus access for talk with decoders
int MobDifferencialChassis::setI2CSlaveToDecoder(){
	return ioctl(file,I2C_SLAVE,decoderAddress);	
}

// Acquire bus access for talk with motors
int MobDifferencialChassis::setI2CSlaveToMotors(){
	return ioctl(file,I2C_SLAVE,motorsAddress);	
}

void MobDifferencialChassis::setDifferencialChassisParameters(DifferencialChassisParameters differencialChassisParameters){
	chassisParam = differencialChassisParameters;
}

// TODO:
void MobDifferencialChassis::setSpeed(Speed speed){

}

// TODO: locks
State MobDifferencialChassis::getState(){
	return robotState;
}

// TODO: locks
Encoders MobDifferencialChassis::getEncoders(){
	return encodersValue;
}

MobDifferencialChassis::~MobDifferencialChassis(){
	close(file);
}

int main(){
	DifferencialChassisParameters chassisParam;
	chassisParam.wheelbase = 0.23f;
	chassisParam.wheelRadius = 0.05f;
	chassisParam.wheelTics = 9200;

	MobDifferencialChassis mobChassis("/dev/i2c-1",0x30,0xb0,chassisParam);
	
	return 0;
}
