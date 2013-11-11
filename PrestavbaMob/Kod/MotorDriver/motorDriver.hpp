#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include <string>
#include <stdint.h>

/*!
 * struct Speed serve for storage speed on the left and right wheels.
 */
struct SpeedMotors{
	int8_t left;
	int8_t right;
	
	SpeedMotors(int8_t left = 0, int8_t right = 0) : left(left), right(right) {};
};

class motorDriver{
public:
    virtual std::string getName()=0;
    
    virtual int setMotorPower(int8_t left, int8_t right)=0;
    virtual int setMotorPower(SpeedMotors speed)=0;
    
    virtual int stop()=0;
};

#endif