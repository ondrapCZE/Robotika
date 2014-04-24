#ifndef BASIC_DIFFERENCIAL_CHASSIS_H
#define BASIC_DIFFERENCIAL_CHASSIS_H

#include <stdint.h>
#include "../../../obecne/basic.h"
#include "../Encoder/encoder.hpp"
#include "../MotorDriver/motorDriver.hpp"

//! PI regulator values
struct PIValue {
	int P; /*! Proportional part. */
	int I; /*! Integral part. */

	float ISum; /*! Sum all differences between actual speed and desire speed. */

	//!  Constructor only assign input parameters in the variables.
	PIValue(const int P = 0, const int I = 0) : P(P), I(I), ISum(0){
	};
};

//! Serve for preserving basic chassis parameters.
struct DiffChassisParam {
	float wheelbase; /*!< Size between wheels in meters. */
	float wheelRadius; /*!< Both wheels have same radius in meters. */
	float maxSpeed; /*!< Chassis are can move only up to this speed in meters per second. */
	unsigned int wheelTics; /*!< How much tics is for one turn wheel. */ 

	PIValue pidLeft;
	PIValue pidRight;

	EncoderReader* encoder; /*!< Chassis have to have encoder on both wheels. */
	MotorDriver* driver; /*!< Motor power driver on the chassis wheels. */

	double metersPerTick;

	//! Constructor only assign input parameters in the variables.
	DiffChassisParam(const float wheelBase = 0,
			const float wheelRadius = 0,
			const float maxSpeed = 0,
			const unsigned int wheelTics = 0,
			const PIValue pidLeft = PIValue(),
			const PIValue pidRight = PIValue(),
			EncoderReader* encoder = std::nullptr_t(),
			MotorDriver* driver = std::nullptr_t()) :
				wheelbase(wheelbase),
				wheelRadius(wheelRadius),
				maxSpeed(maxSpeed),
				wheelTics(wheelTics),
				pidLeft(pidLeft),
				pidRight(pidRight),
				encoder(encoder),
				driver(driver) {
		metersPerTick = (2 * M_PI * wheelRadius) / (float) wheelTics;
	}; 
};

//! Traveled distance on both wheels in meters.
struct WheelsDistance {
	float left; /*! traveled distance on the left wheel in meters */
	float right; /*! traveled distance on the right wheel in meters */

	//! Constructor only assign input parameters in the variables.
	WheelsDistance(const float left = 0, const float right = 0) : left(left), right(right) {
	};
	
	//! Addition between WheelsDistance.
	/*!
	 \param ob2 second WheelsDistance
	 \return new WheelsDistance where parameters are equal 
	  to the addition between same parameter from both WheelsDistance
	 */
	WheelsDistance operator+(const WheelsDistance &ob2) const {
		WheelsDistance temp(left + ob2.left, right + ob2.right);
		return temp;
	};
	
	//! Subtraction between WheelsDistance.
	/*!
	 \param ob2 second WheelsDistance
	 \return new WheelsDistance where parameters are equal 
	  to the subtraction between same parameter from both WheelsDistance
	 */
	WheelsDistance operator-(const WheelsDistance &ob2) const{
		WheelsDistance temp(left - ob2.left, right - ob2.right);
		return temp;
	};
};


 //! Serve for storage speed on the wheels.
struct WheelsSpeed {
	float left; /*! Speed on the left wheel in meters per second. */
	float right; /*! Speed on the right wheel in meters per second. */

	//! Constructor only assign input parameters in the PIValue variables.
	WheelsSpeed(float left = 0, float right = 0) : left(left), right(right) {
	};

	//! Subtraction between WheelsSpeed.
	/*!
	 \param ob2 second WheelsSpeed
	 \return new WheelsSpeed where parameters are equal 
	  to the subtraction between same parameter from both WheelsSpeed
	 */
	WheelsSpeed operator-(WheelsSpeed ob2) {
		WheelsSpeed temp(left - ob2.left, right - ob2.right);
		return temp;
	};
};

 //! Basic virtual differential chassis representation
class BasicDifferentialChassis {
protected:
	DiffChassisParam &diffChassisParam_;
public:
	BasicDifferentialChassis(DiffChassisParam &diffChassisParam) : diffChassisParam_(diffChassisParam) {
	};
	
	
	virtual void stop(bool slow) = 0;
	virtual void setSpeed(const WheelsSpeed speed) = 0;
	virtual void setSpeed(const float left, const float right) = 0;
	virtual State getState() = 0;
	virtual WheelsDistance getWheelDistance() = 0;
	virtual WheelsSpeed getSpeed() = 0;
	virtual float getMaxSpeed(){ return diffChassisParam_.maxSpeed; };
	virtual float getWheelbase(){ return diffChassisParam_.wheelbase; };
};

#endif
