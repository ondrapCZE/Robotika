#ifndef BASIC_DIFFERENCIAL_CHASSIS_H
#define BASIC_DIFFERENCIAL_CHASSIS_H

#include <stdint.h>
#include "../../../obecne/basic.h"
#include "../Encoder/encoder.hpp"
#include "../MotorDriver/motorDriver.hpp"

/*!
 * struct DifferencialChassisParameters serve for preserving basic chassis parameters.
 */
struct DiffChassisParam {
	float wheelbase; /*!< size between wheels in meters */
	float wheelRadius; /*!< both wheels have same radius */
	float maxSpeed; /*!< chassis are can move only up to this speed */
	float reductionRatio; /*!< both wheels have same reduction ratio on motors */
	unsigned int wheelTics; /*!< how much is for one turn wheel */ 

	encoderReader* encoder; /*!< chassis have to have encoder on both wheels */
	motorDriver* driver; /*!< motor power driver on the chassis wheels */

	//! Simple constructor only filling input parameters in the chassis variables 
	DiffChassisParam(float wheelBase = 0, float wheelRadius = 0, float maxSpeed = 0,
		float reductionRatio = 0, unsigned int wheelTics = 0, encoderReader* encoder = NULL,
		motorDriver* driver = NULL) : wheelbase(wheelbase), wheelRadius(wheelRadius),
	maxSpeed(maxSpeed), reductionRatio(reductionRatio), wheelTics(wheelTics),
	encoder(encoder), driver(driver) {
	}; 
};

//! PI regulator values 
struct PIValue {
	int P; /*! Proportional part */
	int I; /*! Integral part*/

	float ISum; /*!  */

	PIValue(int P = 90, int I = 0) : P(P), I(I), ISum(0){
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
	virtual void setSpeed(const float left, const float right) = 0;
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
