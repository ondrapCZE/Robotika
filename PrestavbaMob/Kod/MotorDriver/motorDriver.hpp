#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include <string>
#include <stdint.h>

/*!
 * struct Speed serve for storage speed on the left and right wheels.
 */
struct SpeedMotors{
	int left;
	int right;
	
	SpeedMotors(int left = 0, int right = 0) : left(left), right(right) {};
};

class motorDriver{
public:
    virtual std::string getName()=0;
    virtual unsigned int getMaxPower()=0;
    
    virtual int setMotorPower(int left, int right)=0;
    virtual int setMotorPower(SpeedMotors speed)=0;
    
    virtual int stop()=0;
};

#endif