#include "mobDifferencialChassis.h"

#include <stdio.h>
#include <stdlib.h>
#include <cmath>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>


MobDifferencialChassis::MobDifferencialChassis(std::string I2CName, int decoderAddress, int motorsAddress, DifferencialChassisParameters chassisParam)
 : decoderAddress(decoderAddress), motorsAddress(motorsAddress), chassisParam(chassisParam){
	
	stateMutex = PTHREAD_MUTEX_INITIALIZER;
	speedMutex = PTHREAD_MUTEX_INITIALIZER;
	i2cBusMutex = PTHREAD_MUTEX_INITIALIZER;

	// Open I2C bus for read and write operation
	if((i2cDevice = open(I2CName.c_str(),O_RDWR)) < 0){
		printf("Failed to open bus");
		exit(1);
	}
	
	metersPerTick = (2*M_PI*chassisParam.wheelRadius) / (double) chassisParam.wheelTics;

	// Set motors mode for receive signed value
	setDefaultMotorMode();

	//Test
	sendMotorPower(SpeedMotors(40,40));
	sleep(2);
	sendMotorPower(SpeedMotors(0,0));
	sleep(2);
	// END TEST

	// Set PIRegulator
	PIRegulatorValue.P = 50;
	PIRegulatorValue.I = 1;
	
	encodersAcquireTime = 50; // every x ms
	pthread_create(&updateEncodersThreadHandler, NULL, &updateEncodersThread, (void*) this);
}

// Acquire bus access for talk with decoders
int MobDifferencialChassis::setI2CSlaveToDecoder(){
	return ioctl(i2cDevice,I2C_SLAVE,decoderAddress);	
}

// Acquire bus access for talk with motors
int MobDifferencialChassis::setI2CSlaveToMotors(){
	return ioctl(i2cDevice,I2C_SLAVE,motorsAddress);	
}

Distance MobDifferencialChassis::computeDistance(Encoders distance){
	Distance distanceInMeters;
	distanceInMeters.left = distance.left * metersPerTick;
	distanceInMeters.right = distance.right * metersPerTick;

	return distanceInMeters;
}

Speed MobDifferencialChassis::computeSpeed(Distance distance, double time){
	Speed speed;
	speed.left = distance.left / time;
	speed.right = distance.right / time;

	return speed;
}

Encoders MobDifferencialChassis::getEncodersFromDecoder(){	
	char buffer[BUFFER_SIZE];

	pthread_mutex_lock(&i2cBusMutex);

	if(setI2CSlaveToDecoder()){
		printf("Cannot set i2c slave address to decoder module");
		return 1;
	}	
	
	Encoders encodersState;	
	buffer[0] = 10; // send command for reading encoders value from decoder
	if(write(i2cDevice,buffer,1) != 1){
		printf("Failed to write to the i2c bus. \n\r");
	}else{
		if(read(i2cDevice,buffer,4) != 4){
			printf("Failed to read from the i2c bus. \n\r");
		}else{
			encodersState.right = buffer[0] | (buffer[1] << 8);
			encodersState.left = buffer[2] | (buffer[3] << 8);
			//printf("Buffer [%i,%i,%i,%i] \n\r", buffer[0], buffer[1], buffer[2], buffer[3]);
		}
	}	

	pthread_mutex_unlock(&i2cBusMutex);

	return encodersState;
}

Encoders MobDifferencialChassis::getChangeOfEncoders(){
	Encoders newState = getEncodersFromDecoder();
	Encoders encodersDifference;

	encodersDifference.left = dealWithEncoderOverflow(encodersLastState.left, newState.left);
	encodersDifference.right = dealWithEncoderOverflow(encodersLastState.right, newState.right);

	encodersLastState = newState;
	return encodersDifference;	
}

int MobDifferencialChassis::dealWithEncoderOverflow(int oldValue, int newValue){
	int difference = newValue - oldValue;

	if(abs(difference) < MAX_DIFFERENCE){ // overflow test
		return difference;
	}else{ // overflow
		if(difference < 0){ // top overflow
			return MAX_UINT16 + difference;
		}else{ // bottom overflow
			return difference - MAX_UINT16;
		}
	}
}

int MobDifferencialChassis::setDefaultMotorMode(){	
char buffer[BUFFER_SIZE];

pthread_mutex_lock(&i2cBusMutex);

if(setI2CSlaveToMotors()){
	printf("Cannot set i2c slave address to motor module");
	return 1;
}	

buffer[0] = 0;
buffer[1] = 1;

if(write(i2cDevice,buffer,2) != 2){
	printf("Cannot write to motor module");
	return 1; // error state
}

pthread_mutex_unlock(&i2cBusMutex);
return 0;
}

double MobDifferencialChassis::speedInBoundaries(double speed, double boundaries){
if(speed < boundaries){
	if(speed > -boundaries){
		return speed;
	}
	else{
		return -boundaries;
	}
}else{
	return boundaries;
}
}

int MobDifferencialChassis::sendMotorPower(struct SpeedMotors speedMotors){
char buffer[BUFFER_SIZE];

pthread_mutex_lock(&i2cBusMutex);

	if(setI2CSlaveToMotors()){
		printf("Cannot set i2c slave address to motor module");
		return 1;
	}
	
	buffer[0] = 1;
	buffer[1] = speedMotors.left;

	if(write(i2cDevice,buffer,2) != 2){
		printf("Cannot write to motor module");
		return 1; // error state
	}	

	buffer[0] = 2;
	buffer[1] = speedMotors.right;

	if(write(i2cDevice,buffer,2) != 2){
		printf("Cannot write to motor module");
		return 1; // error state
	}

	pthread_mutex_unlock(&i2cBusMutex);
	return 0;
}

SpeedMotors MobDifferencialChassis::PIRegulator(Speed actualSpeed, Speed desireSpeed){
	Speed speedDifference = desireSpeed - actualSpeed;
	PIRegulatorValue.integralPartLeft += speedDifference.left;
	PIRegulatorValue.integralPartRight += speedDifference.right;

	double speedLeft = PIRegulatorValue.P*speedDifference.left + PIRegulatorValue.I*PIRegulatorValue.integralPartLeft;
	double speedRight = PIRegulatorValue.P*speedDifference.right + PIRegulatorValue.I*PIRegulatorValue.integralPartRight;

	// set in boundaries
	SpeedMotors speedMotors;
	speedMotors.left = (int8_t) speedInBoundaries(speedLeft, MAX_MOTOR_SPEED);
	speedMotors.right = (int8_t) speedInBoundaries(speedRight, MAX_MOTOR_SPEED);

	return speedMotors;
}

void* MobDifferencialChassis::updateEncodersThread(void* ThisPointer){
	timeval timer[2];
	MobDifferencialChassis* This = (MobDifferencialChassis *) ThisPointer;
	printf("Sleep time: %i \n\r", This->encodersAcquireTime);
	This->encodersLastState = This->getEncodersFromDecoder();

	long int lastMicroTime = 1;
	while(true){
		gettimeofday(&timer[0], NULL);
		long int microStart = (timer[0].tv_sec * 1000000) + (timer[0].tv_usec);

		// Get encoders and compute distance
		Encoders differenceEncoders = This->getChangeOfEncoders();

		// Compute actual speed and use PID
		double time = (microStart - lastMicroTime) / 1000000.0f; // time in sec
		Distance distance = This->computeDistance(differenceEncoders);
		Speed actualSpeed = This->computeSpeed(distance, time);
		printf("Actual speed left: %f  right: %f \n\r", actualSpeed.left, actualSpeed.right);
	
		pthread_mutex_lock(&This->speedMutex);
		SpeedMotors valueMotors = This->PIRegulator(actualSpeed, This->desireSpeed);
		pthread_mutex_unlock(&This->speedMutex);
		printf("Send motor speed left: %i right: %i \n\r", valueMotors.left, valueMotors.right);		

		This->sendMotorPower(valueMotors);			
	
		gettimeofday(&timer[1], NULL);
		long int microStop = (timer[1].tv_sec * 1000000) + (timer[1].tv_usec);
		long int sleepMicro = This->encodersAcquireTime*1000 - (microStop - microStart);
		lastMicroTime = microStart;
		
		printf("Usleep time: %li \n\r", sleepMicro);
		usleep(sleepMicro);
	}

	return 0;
}


void MobDifferencialChassis::setDifferencialChassisParameters(DifferencialChassisParameters differencialChassisParameters){
	chassisParam = differencialChassisParameters;
	metersPerTick = (2*M_PI*differencialChassisParameters.wheelRadius) / (double) differencialChassisParameters.wheelTics;
}

// TODO:
void MobDifferencialChassis::setSpeed(Speed speed){
	speed.left = speedInBoundaries(speed.left, MAX_SPEED);
	speed.right = speedInBoundaries(speed.right, MAX_SPEED);	

	pthread_mutex_lock(&speedMutex);
	desireSpeed = speed;
	pthread_mutex_unlock(&speedMutex);
}

 
State MobDifferencialChassis::getState(){
	pthread_mutex_lock(&stateMutex);
	State copyState = robotState;
	pthread_mutex_unlock(&stateMutex);

	return copyState;
}

MobDifferencialChassis::~MobDifferencialChassis(){
	close(i2cDevice);
}

int main(){
	DifferencialChassisParameters chassisParam;
	chassisParam.wheelbase = 0.23f;
	chassisParam.wheelRadius = 0.05f;
	chassisParam.wheelTics = 9200;

	MobDifferencialChassis mobChassis("/dev/i2c-1",0x30,0x58,chassisParam);

	while(true){
		//Encoders encoders = mobChassis.getEncoders();
		//printf("Main encoders left: %i right: %i \n\r", encoders.left, encoders.right);
		Speed desire(-0.2f,-0.2f);
		mobChassis.setSpeed(desire);
		usleep(500000);

		//Speed stop(0,0);
		//mobChassis.setSpeed(stop);		
		//sleep(5);
	}
	
	return 0;
}
