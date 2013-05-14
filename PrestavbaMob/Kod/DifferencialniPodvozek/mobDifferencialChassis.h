#ifndef DIFFERENCIAL_CHASSIS_H
#define DIFFERENCIAL_CHASSIS_H

#include "basicDifferencialChassis.h"
#include <string>
#include <pthread.h>

#define BUFFER_SIZE 10
#define MAX_SPEED 0.5f
#define MAX_MOTOR_SPEED 127
#define MAX_DIFFERENCE (MAX_UINT16 / 2)
#define MAX_UINT16 65535

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

	Encoders encodersLastState;

	DifferencialChassisParameters chassisParam;
	double metersPerTick;

	PIValue PIRegulatorValue;

	State robotState;
	WheelDistance wheelDistance;
	Speed desireSpeed;

	pthread_t updateEncodersThreadHandler;

	pthread_mutex_t i2cBusMutex;
	pthread_mutex_t stateMutex;
	pthread_mutex_t speedMutex;

	int setI2CSlaveToDecoder();
	int setI2CSlaveToMotors();

	WheelDistance computeDistance(Encoders distance);
	Speed computeSpeed(WheelDistance distance, float time); // distance in m and time in sec

	Encoders getEncodersFromDecoder();
	Encoders getChangeOfEncoders();
	int dealWithEncoderOverflow(int oldValue, int newValue);

	void changeRobotState(WheelDistance change);

	int setDefaultMotorMode();
	float speedInBoundaries(float speed, float boudaries);
	int sendMotorPower(struct SpeedMotors speedMotors);
	SpeedMotors PIRegulator(Speed actualSpeed, Speed desireSpeed);

	static void* updateEncodersThread(void* ThisPointer); // time in ms	
public:
	MobDifferencialChassis(std::string I2CName = "/dev/i2c-1", int decoderAddress = 0x30, int motorsAddress = 0x58);
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

	WheelDistance getWheelDistance();

	~MobDifferencialChassis();
};

#endif
