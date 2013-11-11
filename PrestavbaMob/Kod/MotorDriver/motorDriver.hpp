#ifndefdef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include <string>

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
    virtual std::string getName();
    virtual int getMaximumMotorSpeed();
    
    virtual void setMotorPower(int left, int right)=0;
    virtual void setMotorPower(SpeedMotors speed)=0;
    
    virtual void stop()=0;
};

#endif