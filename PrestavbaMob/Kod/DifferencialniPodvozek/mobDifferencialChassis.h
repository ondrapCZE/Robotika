#ifndef DIFFERENCIAL_CHASSIS_H
#define DIFFERENCIAL_CHASSIS_H

#include "basicDifferencialChassis.h"

class MobDifferencialChasis : public BasicDifferencialChassis{
private:
	
public:
	//! A pure virtual member.
    /*!
		\param differencialChassisParameters an struct DifferencialChassisParameters argument.
    */
	virtual void setDifferencialChassisParameters(DifferencialChassisParameters differencialChassisParameters);
	//! A pure virtual member.
    /*!
		\param speed an struct Speed argument.
    */
	virtual void setSpeed(Speed speed);
	//! A pure virtual member.
    /*!
		\return actual state of the chassis
	*/
	virtual state getState();
	//! A pure virtual member.
    /*!
		\return actual state of encoders
    */
	virtual encoders getEncoders();
};

#endif