#ifndef BASIC_DIFFERENCIAL_CHASSIS_H
#define BASIC_DIFFERENCIAL_CHASSIS_H

#include <stdint.h>
#include "../../../obecne/basic.h"
#include "../Encoder/encoder.hpp"
#include "../MotorDriver/motorDriver.hpp"
/*!
 * struct DifferencialChassisParameters serve for setting basic parameters.
 */
struct DiffChassisParm{
	float wheelBase;
	float wheelRadius;
	float maxSpeed;
	float reductionRatio;
	unsigned int wheelTics;
	
	encoderReader* encoder;
	motorDriver* driver;
};

struct PIValue {
	int P;
	int I;

	float integralPartLeft;
	float integralPartRight;

	PIValue(int P = 90, int I = 0) : P(P), I(I), integralPartLeft(0), integralPartRight(0) {
	};
};

struct WheelsDistance {
	float left;
	float right;

	WheelsDistance(float left = 0, float right = 0) : left(left), right(right) {
	};
};

/*!
 * struct Speed serve for storage speed on the left and right wheels.
 */
struct WheelsSpeed {
	float left;
	float right;

	WheelsSpeed(float left = 0, float right = 0) : left(left), right(right) {
	};

	WheelsSpeed operator-(WheelsSpeed ob2) {
		WheelsSpeed temp(left - ob2.left, right - ob2.right);
		return temp;
	};
};

/*!
 * struct DifferencialChassis is virtual class which is necessary to define.
 */
class BasicDifferencialChassis {
public:
	//! A pure virtual member.
	/*!
	\param differencialChassisParameters an struct DifferencialChassisParameters argument.
	 */
	virtual void setDifferencialChassisParameters(DiffChassisParm differencialChassisParameters) = 0;
	//! A pure virtual member.
	/*!
	\param speed an struct Speed argument.
	 */
	virtual void stop() = 0;
	virtual void setSpeed(WheelsSpeed speed) = 0;
	//! A pure virtual member.
	/*!
	\return actual state of the chassis
	 */
	virtual State getState() = 0;

	//! A pure virtual member

	/*!
		\return actual distance on both wheels
	 */
	virtual WheelsDistance getWheelDistance() = 0;

	virtual float getMaxSpeed() = 0;
};

#endif
