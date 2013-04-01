#ifndef BASIC_DIFFERENCIAL_CHASSIS_H
#define BASIC_DIFFERENCIAL_CHASSIS_H

#include <stdint.h>
#include "../../../obecne/basic.h"
#include "../Dekoder/decoder.h"

/*!
 * struct Speed serve for storage speed on the left and right wheels.
 */
struct Speed{
	uint8_t left;
	uint8_t right;
};

/*!
 * struct DifferencialChassisParameters serve for setting basic parameters.
 */
struct DifferencialChassisParameters{
	unsigned int wheelbase;
	unsigned int wheelRadius;
	unsigned int wheelTics;
};

/*!
 * struct DifferencialChassis is virtual class which is necessary to define.
 */
class BasicDifferencialChassis{
public:
	//! A pure virtual member.
    /*!
		\param differencialChassisParameters an struct DifferencialChassisParameters argument.
    */
	virtual void setDifferencialChassisParameters(DifferencialChassisParameters differencialChassisParameters)=0;
	//! A pure virtual member.
    /*!
		\param speed an struct Speed argument.
    */
	virtual void setSpeed(Speed speed)=0;
	//! A pure virtual member.
    /*!
		\return actual state of the chassis
	*/
	virtual state getState()=0;
	//! A pure virtual member.
    /*!
		\return actual state of encoders
    */
	virtual encoders getEncoders()=0;
};

#endif