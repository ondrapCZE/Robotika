#ifndef MOTOR_DRIVER_SABERTOOTH_H
#define MOTOR_DRIVER_SABERTOOTH_H

#include "motorDriver.hpp"

#define BUFFER_SIZE 10
#define BAUDRATE_SET B38400

class motorDriverSabertooth{
    int serialDevice;
    unsigned char buffer[BUFFER_SIZE];
public:
    motorDriverSabertooth(std::string device);
    std::string getName();
    
    int setMotorPower(int8_t left, int8_t right);
    int setMotorPower(SpeedMotors speed);
    
    int stop();
    ~motorDriverSabertooth(){close(serialDevice);};
};

#endif