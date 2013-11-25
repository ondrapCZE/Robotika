#ifndef MOTOR_DRIVER_MD22_H
#define MOTOR_DRIVER_MD22_H
#define BUFFER_SIZE 2
// int motorsAddress = 0x58 for mob md22

#include "motorDriver.hpp"

class motorDriverMD22 : public motorDriver{
    int i2cDevice;
    static const unsigned int maxPower = 127;
    unsigned char buffer[BUFFER_SIZE];
public:
    motorDriverMD22(std::string deviceI2C,int driverAddress);
    std::string getName();
    unsigned int getMaxPower();
    
    int setDefaultMotorMode();
    int setMotorsPower(int left, int right);
    int setMotorsPower(motorsPower power);
    
    int stop();
    ~motorDriverMD22(){close(i2cDevice);};
};

#endif