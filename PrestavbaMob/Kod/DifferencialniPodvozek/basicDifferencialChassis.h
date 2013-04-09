#ifndef BASIC_DIFFERENCIAL_CHASSIS_H
#define BASIC_DIFFERENCIAL_CHASSIS_H

#include <stdint.h>
#include "../../../obecne/basic.h"

/*!
 * struct Speed serve for storage speed on the left and right wheels.
 */
struct Speed{
	double left;
	double right;
};

/*!
 * struct DifferencialChassisParameters serve for setting basic parameters.
 */
struct DifferencialChassisParameters{
	double wheelbase;
	double wheelRadius;
	unsigned int wheelTics;
};

struct Encoders{
	unsigned int left;
	unsigned int right;

	Encoders(unsigned int left = 0, unsigned int right = 0) : left(left), right(right) {};
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
	virtual State getState()=0;
	//! A pure virtual member.
    /*!
		\return actual state of encoders
    */
	virtual Encoders getEncoders()=0;
};

#endif
