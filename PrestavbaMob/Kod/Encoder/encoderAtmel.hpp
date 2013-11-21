#ifndef ENCODER_ATMEL_H
#define ENCODER_ATMEL_H

#include "encoder.hpp"

#include <string>

class encoderAtmel : public encoder{
    // I2C description for comunication
    int i2cDevice;
    Encoders encodersLastState;
    
    int dealWithEncoderOverflow(int oldValue, int newValue);
public:
    encoderAtmel(std::string I2CDevice = "/dev/i2c-1", int decoderAddress = 0x30);
    unsigned int getEncodersResolution();
    Encoders getEncodersState();
    Encoders getChangeOfEncoders();
    ~encoderAtmel(){close(i2cDevice);};
};


#endif