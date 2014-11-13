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

	double ISum; /*! Sum all differences between actual speed and desire speed. */

	//!  Constructor only assign input parameters in the variables.
	PIValue(const int P = 0, const int I = 0) : P(P), I(I), ISum(0){
	};
};

//! Preserve basic chassis parameters.
struct DiffChassisParam {
	double wheelbase; /*!< Size between wheels in meters. */
	double wheelRadius; /*!< Both wheels have same radius in meters. */
	double maxVelocity; /*!< Chassis can move only up to this speed in meters per second. */
	unsigned int wheelTics; /*!< How much tics is for one wheel turn. */ 

	PIValue pidLeft;
	PIValue pidRight;

	EncoderReader* encoder; /*!< Chassis have to have encoder on both wheels. */
	MotorDriver* driver; /*!< Motor power driver on the chassis wheels. */

    double metersPerTick; /*!< Ratio between encoder tic and traversed wheel distance  */

	//! Constructor only assign input parameters in to the variables.
	DiffChassisParam(const double wheelBase = 0,
			const double wheelRadius = 0,
			const double maxSpeed = 0,
			const unsigned int wheelTics = 0,
			const PIValue pidLeft = PIValue(),
			const PIValue pidRight = PIValue(),
			EncoderReader* encoder = std::nullptr_t(),
			MotorDriver* driver = std::nullptr_t()) :
				wheelbase(wheelBase),
				wheelRadius(wheelRadius),
				maxVelocity(maxSpeed),
				wheelTics(wheelTics),
				pidLeft(pidLeft),
				pidRight(pidRight),
				encoder(encoder),
				driver(driver) {
		metersPerTick = (2 * M_PI * wheelRadius) / (double) wheelTics;
	}; 
};

//! Traveled distance on both wheels in meters.
struct DistanceWheels {
	double left; /*! traveled distance on the left wheel in meters */
	double right; /*! traveled distance on the right wheel in meters */

	//! Constructor only assign input parameters in the variables.
	DistanceWheels(const double left = 0, const double right = 0) : left(left), right(right) {
	};
	
	//! Addition between WheelsDistance.
	/*!
	 \param ob2 second WheelsDistance
	 \return new WheelsDistance where parameters are equal 
	  to the addition between same parameter from both WheelsDistance
	 */
	DistanceWheels operator+(const DistanceWheels &ob2) const {
		DistanceWheels temp(left + ob2.left, right + ob2.right);
		return temp;
	};
	
	//! Subtraction between WheelsDistance.
	/*!
	 \param ob2 second WheelsDistance
	 \return new WheelsDistance where parameters are equal 
	  to the subtraction between same parameter from both WheelsDistance
	 */
	DistanceWheels operator-(const DistanceWheels &ob2) const{
		DistanceWheels temp(left - ob2.left, right - ob2.right);
		return temp;
	};
};


 //! Serve for storage speed on the wheels.
struct VelocityWheels {
	double left; /*! Speed on the left wheel in meters per second. */
	double right; /*! Speed on the right wheel in meters per second. */

	//! Constructor only assign input parameters in the PIValue variables.
	VelocityWheels(double left = 0, double right = 0) : left(left), right(right) {
	};

	//! Subtraction between WheelsSpeed.
	/*!
	 \param ob2 second WheelsSpeed
	 \return new WheelsSpeed where parameters are equal 
	  to the subtraction between same parameter from both WheelsSpeed
	 */
	VelocityWheels operator-(VelocityWheels ob2) {
		VelocityWheels temp(left - ob2.left, right - ob2.right);
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
	virtual void setVelocity(const VelocityWheels speed) = 0;
	virtual void setVelocity(const double distance, const double angle) = 0;
	virtual State getState() = 0;
	virtual DistanceWheels getDistanceWheels() = 0;
	virtual VelocityWheels getVelocityWheels() = 0;
	virtual double getMaxVelocity(){ return diffChassisParam_.maxVelocity; };
	virtual double getWheelbase(){ return diffChassisParam_.wheelbase; };
};

#endif
