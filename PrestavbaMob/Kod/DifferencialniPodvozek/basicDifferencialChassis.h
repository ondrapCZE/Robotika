#ifndef BASIC_DIFFERENCIAL_CHASSIS_H
#define BASIC_DIFFERENCIAL_CHASSIS_H

#include <stdint.h>
#include "../../../obecne/basic.h"

/*!
 * struct DifferencialChassisParameters serve for setting basic parameters.
 */
struct DifferencialChassisParameters{
	float wheelbase;
	float wheelRadius;
        float maxSpeed;
	unsigned int wheelTics;
};

struct PIValue{
	int P;
	int I;

	float integralPartLeft;
	float integralPartRight;

	PIValue(int P=90, int I=0): P(P), I(I), integralPartLeft(0), integralPartRight(0)  {};
};

struct WheelDistance{
	float left;
	float right;

	WheelDistance(float left = 0, float right = 0) : left(left), right(right) {};
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
        virtual void stop()=0;
	virtual void setSpeed(Speed speed)=0;
	//! A pure virtual member.
    /*!
		\return actual state of the chassis
	*/
	virtual State getState()=0;

	//! A pure virtual member

	/*!
	 	\return actual distance on both wheels
	 */
	virtual WheelDistance getWheelDistance()=0;
        
        virtual float getMaxSpeed()=0;
};

#endif
