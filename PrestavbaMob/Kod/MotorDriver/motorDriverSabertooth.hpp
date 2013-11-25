#ifndef MOTOR_DRIVER_SABERTOOTH_H
#define MOTOR_DRIVER_SABERTOOTH_H

#include <termios.h> /* POSIX terminal control definitions */

#include "motorDriver.hpp"

class motorDriverSabertooth : public motorDriver{
    static const unsigned int maxPower = 63;
    static const unsigned int BUFFER_SIZE = 2;
    static const unsigned int BAUDRATE_SET = B38400;
    
    int serialDevice;
    unsigned char buffer[BUFFER_SIZE];
public:
    motorDriverSabertooth(std::string device);
    std::string getName();
    unsigned int getMaxPower();
    
    int setMotorsPower(int left, int right);
    int setMotorsPower(motorsPower speed);
    
    int stop();
    ~motorDriverSabertooth(){close(serialDevice);};
};

#endif