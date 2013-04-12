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
	int8_t left;
	int8_t right;
	
	SpeedMotors(int8_t left = 0, int8_t right = 0) : left(left), right(right) {};
};

struct Distance{
	double left;
	double right;

	Distance(double left=0, double right=0) : left(left), right(right){};
};

class MobDifferencialChassis : public BasicDifferencialChassis{
private:
	// I2C description for comunication
	int i2cDevice;
	int decoderAddress;
	int motorsAddress;
	int encodersAcquireTime;

	Encoders encodersValue;	

	DifferencialChassisParameters chassisParam;
	double metersPerTick;

	PIValue PIRegulatorValue;

	State robotState;
	Speed desireSpeed;

	pthread_t updateEncodersThreadHandler;

	pthread_mutex_t i2cBusMutex;
	pthread_mutex_t encodersMutex;
	pthread_mutex_t stateMutex;
	pthread_mutex_t speedMutex;

	int setI2CSlaveToDecoder();
	int setI2CSlaveToMotors();

	Distance computeDistance(Encoders distance);
	Speed computeSpeed(Distance distance, double time); // distance in m and time in sec
	Encoders getEncodersFromDecoder();

	int setDefaultMotorMode();
	int sendMotorPower(struct SpeedMotors speedMotors);
	SpeedMotors PIRegulator(Speed actualSpeed, Speed desireSpeed);

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
