#ifndef DIFFERENCIAL_CHASSIS_H
#define DIFFERENCIAL_CHASSIS_H

#include "basicDifferencialChassis.h"
#include <string>
#include <pthread.h>

#define BUFFER_SIZE 10

/*!
 * struct Speed serve for storage speed on the left and right wheels.
 */
struct SpeedMotors{
	uint8_t left;
	uint8_t right;
};

class MobDifferencialChassis : public BasicDifferencialChassis{
private:
	// I2C description for comunication
	int file;
	int decoderAddress;
	int motorsAddress;
	int encodersAcquireTime;

	Encoders encodersValue;	

	DifferencialChassisParameters chassisParam;

	State robotState;

	pthread_t updateEncodersThreadHandler;

	pthread_mutex_t i2cBusMutex;
	pthread_mutex_t encodersMutex;
	pthread_mutex_t stateMutex;

	int setI2CSlaveToDecoder();
	int setI2CSlaveToMotors();
	Encoders getEncodersFromDecoder();

	static void* updateEncodersThread(void* ThisPointer); // time in ms	
public:
	MobDifferencialChassis(std::string I2CName, int decoderAddress, int motorsAddress, DifferencialChassisParameters chassisParam);
	//! 
    /*!
		\param differencialChassisParameters an struct DifferencialChassisParameters argument.
	*/
	void setDifferencialChassisParameters(DifferencialChassisParameters differencialChassisParameters);
	//! 
    /*!
		\param speed an struct Speed argument.
    */
	void setSpeed(Speed speed);
	//! 
    /*!
		\return actual state of the chassis
	*/
	State getState();
	//! 
    /*!
		\return actual state of encoders
    */
	Encoders getEncoders();

	~MobDifferencialChassis();
};

#endif
