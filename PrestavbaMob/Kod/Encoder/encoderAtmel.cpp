#include <stdio.h>
#include <stdlib.h>
#include <cmath>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>

#include "encoderAtmel.hpp"
#include "../../../obecne/basic.h"

int encoderAtmel::dealWithEncoderOverflow(const int oldValue,const int newValue){
        int difference = newValue - oldValue;

	if(abs(difference) < MAX_DIFFERENCE){ // overflow test
		return difference;
	}else{ // overflow
		if(difference < 0){ // top overflow
			return MAX_UINT16 + difference;
		}else{ // bottom overflow
			return difference - MAX_UINT16;
		}
	}
}

encoderAtmel::encoderAtmel(const std::string I2CDevice,const int decoderAddress){
        // Open I2C bus for read and write operation
	if((i2cDevice = open(I2CDevice.c_str(),O_RDWR)) < 0){
		printf("Failed to open bus");
		exit(1);
	}

        if(ioctl(i2cDevice,I2C_SLAVE,decoderAddress) < 0){
        	printf("Failed to set decoder address bus");
		exit(1);
        }
        
        encodersLastState = getEncodersState();
}

unsigned int encoderAtmel::getEncodersResolution(){
    return 1024; // encoders have 10bit resolution
}

//TODO: Divide this function to two. First for data acquisition and second for 
// testing validity of data.
Encoders encoderAtmel::getEncodersState(){
        unsigned char buffer[BUFFER_SIZE];
	Encoders encodersState;		

        bool error = false;
        uint8_t crc;
        do{
            buffer[0] = 10; // send command for reading encoders value from decoder
            if(write(i2cDevice,buffer,1) != 1){
                    printf("Failed to write to the i2c bus. \n\r");
            }else{
                    if(read(i2cDevice,buffer,5) != 5){
                            printf("Failed to read from the i2c bus. \n\r");
                    }else{ // Test data validity
                            crc = 0;
                            for(uint8_t i = 0; i<4; ++i){
                                crc = basic_robotic_fce::crc8(crc, buffer[i]);
                            }

                            if(crc == buffer[4]){
                                    encodersState.right = buffer[0] | (buffer[1] << 8);
                                    encodersState.left = buffer[2] | (buffer[3] << 8);
                            //printf("Buffer [%i,%i,%i,%i] \n\r", buffer[0], buffer[1], buffer[2], buffer[3]);
                            }else{
                                printf("Bad data transport. Wrong CRC. \n\r");
                            }
                    }
            }
        }while(!error & (crc != buffer[4]));	

        //printf("Encoders [%i,%i] \n\r", encodersState.left, encodersState.right);
	return encodersState;
}

Encoders encoderAtmel::getChangeOfEncoders(){
        Encoders newState = getEncodersState();
	Encoders encodersDifference;

	encodersDifference.left = dealWithEncoderOverflow(encodersLastState.left, newState.left);
	encodersDifference.right = dealWithEncoderOverflow(encodersLastState.right, newState.right);

	encodersLastState = newState;
	return encodersDifference;	
}
        