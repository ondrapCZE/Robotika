#include "motorDriverMD22.hpp"

#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>

motorDriverMD22::motorDriverMD22(std::string deviceI2C, int driverAddress){
    // Open I2C bus for read and write operation
        if((i2cDevice = open(deviceI2C.c_str(),O_RDWR)) < 0){
		printf("Failed to open I2C bus \n");
		exit(1);
	}
        
        if(ioctl(i2cDevice,I2C_SLAVE,driverAddress) < 0){
                printf("Failed to set slave adress \n");
		exit(1);
        }
}

std::string motorDriverMD22::getName(){
    return "MD22 motor driver over I2C";
}
 
int motorDriverMD22::setDefaultMotorMode(){	
	int returnState = 0;	

	buffer[0] = 0;
	buffer[1] = 0;

	if(write(i2cDevice,buffer,2) != 2){
		printf("Cannot write to motor module \n\r");
		returnState = 1; // error state
	}

	return returnState;
}

int motorDriverMD22::setMotorPower(int8_t left, int8_t right){
    SpeedMotors speed(left,right);
    return setMotorPower(speed);
}

int motorDriverMD22::setMotorPower(SpeedMotors speed){
	int returnState = 0;

	buffer[0] = 1;
	buffer[1] = speed.left + 128;

	if(write(i2cDevice,buffer,2) != 2){
		printf("Cannot write to motor module \n\r");
		returnState = 1; // error state
	}else{	

                buffer[0] = 2;
                buffer[1] = speed.right + 128;

                if(write(i2cDevice,buffer,2) != 2){
                        printf("Cannot write to motor module \n\r");
                        returnState = 1; // error state
                }
        }

	return returnState;
}
    
int motorDriverMD22::stop(){
    SpeedMotors speed(0,0);
    return setMotorPower(speed);
}