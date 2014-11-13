#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include <string>
#include <stdint.h>

//! Define power applied on the left and right wheel.
struct motorsPower {
	int left;
	int right;

	motorsPower(int left = 0, int right = 0) : left(left), right(right) {
	};
};

//! General overlayer for power module for two wheels.
/*! Describe general communication with power module.
 */

class MotorDriver {
public:
	//! Virtual destructor can be overwritten in derived class.
	virtual ~MotorDriver(){};
	//! Return power module name
	virtual std::string getName() = 0;
	//! Return max power which module can set to a motor
	virtual unsigned int getMaxPower() = 0;
	//! Set power applied on both motors.
	/*! \param left power applied on left motor
	 *  \param right power applied on right motor
	 *  \return error code. Zero means that all goes well.
	 */
	virtual int setMotorsPower(const int left, const int right) = 0;
	//! Set power applied on both motors.
	/*! \param motorsPower power applied on both motors.
	 *  \return error code. Zero means that all goes well.
	 */
	virtual int setMotorsPower(const motorsPower power) = 0;

	//! Immediately stop both motors.
	/*!
	 *  \return error code. Zero means that all goes well.
	 */
	virtual int stop() = 0;
};

#endif
