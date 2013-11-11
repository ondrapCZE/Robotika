#ifndef MOTOR_DRIVER_MD22_H
#define MOTOR_DRIVER_MD22_H
#define BUFFER_SIZE 2
// int motorsAddress = 0x58 for mob md22

#include <string>

#include "motorDriver.hpp"

class motorDriverMD22 : public motorDriver{
    int i2cDevice;
    unsigned char buffer[BUFFER_SIZE];
public:
    motorDriverMD22(std::string deviceI2C,int driverAddress);
    std::string getName();
    
    int setDefaultMotorMode();
    int setMotorPower(int8_t left, int8_t right);
    int setMotorPower(SpeedMotors speed);
    
    int stop();
    ~motorDriverMD22(){close(i2cDevice);};
};

#endif