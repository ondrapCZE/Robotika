#ifndef BASIC_DIFFERENCIAL_CHASSIS_H
#define BASIC_DIFFERENCIAL_CHASSIS_H

#include <stdint.h>
#include "../../../obecne/basic.h"
#include "../Encoder/encoder.hpp"
#include "../MotorDriver/motorDriver.hpp"

/*!
 * struct DifferencialChassisParameters serve for setting basic parameters.
 */
struct DiffChassisParam {
	float wheelbase;
	float wheelRadius;
	float maxSpeed;
	float reductionRatio;
	unsigned int wheelTics;

	encoderReader* encoder;
	motorDriver* driver;

	DiffChassisParam(float wheelBase = 0, float wheelRadius = 0, float maxSpeed = 0,
		float reductionRatio = 0, unsigned int wheelTics = 0, encoderReader* encoder = NULL,
		motorDriver* driver = NULL) : wheelbase(wheelbase), wheelRadius(wheelRadius),
	maxSpeed(maxSpeed), reductionRatio(reductionRatio), wheelTics(wheelTics),
	encoder(encoder), driver(driver) {
	};
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
	
	WheelsDistance operator+(const WheelsDistance &ob2) const {
		WheelsDistance temp(left + ob2.left, right + ob2.right);
		return temp;
	};
	
	WheelsDistance operator-(const WheelsDistance &ob2) const{
		WheelsDistance temp(left - ob2.left, right - ob2.right);
		return temp;
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
protected:
	DiffChassisParam diffChassisParam;
public:
	BasicDifferencialChassis(const DiffChassisParam diffChassisParam) : diffChassisParam(diffChassisParam) {
	};
	
	//! A pure virtual member.
	/*!
	\param speed an struct Speed argument.
	 */
	virtual void stop() = 0;
	virtual void setSpeed(const WheelsSpeed speed) = 0;
	virtual void setSpeed(const float left, const float right){ setSpeed(WheelsSpeed(left,right)); };
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

	virtual float getSpeed() = 0;	
	virtual float getMaxSpeed(){ return diffChassisParam.maxSpeed; };
	virtual float getWheelbase(){ return diffChassisParam.wheelbase; };
};

#endif
