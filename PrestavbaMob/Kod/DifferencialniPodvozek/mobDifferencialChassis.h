#ifndef DIFFERENCIAL_CHASSIS_H
#define DIFFERENCIAL_CHASSIS_H

#include "basicDifferencialChassis.h"
#include <string>

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

	Encoders encodersValue;	

	DifferencialChassisParameters chassisParam;

	State robotState;

	int setI2CSlaveToDecoder();
	int setI2CSlaveToMotors();

	
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
