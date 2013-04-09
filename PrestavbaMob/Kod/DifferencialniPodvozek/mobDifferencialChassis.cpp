#include "mobDifferencialChassis.h"

#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>


MobDifferencialChassis::MobDifferencialChassis(std::string I2CName, int decoderAddress, int motorsAddress, DifferencialChassisParameters chassisParam)
 : decoderAddress(decoderAddress), motorsAddress(motorsAddress), chassisParam(chassisParam){
	
	stateMutex = PTHREAD_MUTEX_INITIALIZER;
	encodersMutex = PTHREAD_MUTEX_INITIALIZER;
	i2cBusMutex = PTHREAD_MUTEX_INITIALIZER;

	// Open I2C bus for read and write operation
	if((file = open(I2CName.c_str(),O_RDWR)) < 0){
		printf("Failed to open bus");
		exit(1);
	}
	
	encodersAcquireTime = 1000;
	pthread_create(&updateEncodersThreadHandler, NULL, &updateEncodersThread, (void*) this);
}

// Acquire bus access for talk with decoders
int MobDifferencialChassis::setI2CSlaveToDecoder(){
	return ioctl(file,I2C_SLAVE,decoderAddress);	
}

// Acquire bus access for talk with motors
int MobDifferencialChassis::setI2CSlaveToMotors(){
	return ioctl(file,I2C_SLAVE,motorsAddress);	
}

Encoders MobDifferencialChassis::getEncodersFromDecoder(){	
	char buffer[BUFFER_SIZE];
	Encoders encodersState;	

	pthread_mutex_lock(&i2cBusMutex);
	
	setI2CSlaveToDecoder();
	buffer[0] = 10; // send command for reading encoders value from decoder
	if(write(file,buffer,1) != 1){
		printf("Failed to write to the i2c bus. \n\r");
	}else{
		if(read(file,buffer,4) != 4){
			printf("Failed to read from the i2c bus. \n\r");
		}else{
			encodersState.left = buffer[0] | (buffer[1] << 8);
			encodersState.right = buffer[2] | (buffer[3] << 8);
		}
	}	

	pthread_mutex_unlock(&i2cBusMutex);

	return encodersState;
}

void* MobDifferencialChassis::updateEncodersThread(void* ThisPointer){
	timeval timer[2];
	MobDifferencialChassis* This = (MobDifferencialChassis *) ThisPointer;
	printf("Sleep time: %i \n\r", This->encodersAcquireTime);

	while(true){
		gettimeofday(&timer[0], NULL);
		
		Encoders encodersState = This->getEncodersFromDecoder();
		printf("Encoders left: %i right: %i \n\r", encodersState.left, encodersState.right);

		gettimeofday(&timer[1], NULL);

		long int millisStart = (timer[0].tv_sec * 1000) + (timer[0].tv_usec / 1000);
		long int millisStop = (timer[1].tv_sec * 1000) + (timer[1].tv_usec / 1000);
		int sleepMillis = This->encodersAcquireTime - (millisStop - millisStart);
		
		printf("Usleep time: %i \n\r", sleepMillis);
		usleep(sleepMillis * 1000);
	}

	return 0;
}


void MobDifferencialChassis::setDifferencialChassisParameters(DifferencialChassisParameters differencialChassisParameters){
	chassisParam = differencialChassisParameters;
}

// TODO:
void MobDifferencialChassis::setSpeed(Speed speed){

}

 
State MobDifferencialChassis::getState(){
	pthread_mutex_lock(&stateMutex);
	State copyState = robotState;
	pthread_mutex_unlock(&stateMutex);

	return copyState;
}

 
Encoders MobDifferencialChassis::getEncoders(){
	pthread_mutex_lock(&encodersMutex);
	Encoders copyEncoders = encodersValue;
	pthread_mutex_unlock(&encodersMutex);

	return copyEncoders;
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

	while(true);
	
	return 0;
}
