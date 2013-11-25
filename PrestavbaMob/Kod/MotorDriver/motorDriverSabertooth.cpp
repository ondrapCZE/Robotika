#include "motorDriverSabertooth.hpp"

#include <stdio.h>
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include <stdlib.h>

motorDriverSabertooth::motorDriverSabertooth(std::string device){
        serialDevice = open(device.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);
    
        if(serialDevice < -1){
                printf("Cannot open serial device: %s \n\r", device.c_str());
                exit(1);
        }
    
        termios termiosSerialParams;

        tcgetattr(serialDevice,&termiosSerialParams);

	termiosSerialParams.c_cflag &= ~PARENB;
	termiosSerialParams.c_cflag &= ~CSTOPB;
	termiosSerialParams.c_cflag &= ~CSIZE;
	termiosSerialParams.c_cflag |= CS8;

	cfsetispeed(&termiosSerialParams, BAUDRATE_SET);
	cfsetospeed(&termiosSerialParams, BAUDRATE_SET);

	termiosSerialParams.c_cflag |= (CLOCAL | CREAD);

	tcsetattr(serialDevice, TCSANOW, &termiosSerialParams);
}

std::string motorDriverSabertooth::getName(){
    return "Sabertooth 2x5 motor driver over serial line\n\r";
}

unsigned int motorDriverSabertooth::getMaxPower(){
    return maxPower;
}
    
int motorDriverSabertooth::setMotorsPower(int left, int right){
    return setMotorsPower(motorsPower(left,right));
}

int motorDriverSabertooth::setMotorsPower(motorsPower speed){
        int returnState = 0;
        
        //TODO: check whether value is in range of motor power
        
        uint8_t left = (speed.left/2) + 64;
        uint8_t right = (speed.right/2) + 192;
        
        buffer[0] = left;
        buffer[1] = right;
        if(write(serialDevice,buffer,2) != 2){
		printf("Cannot write to motor module \n\r");
		returnState = 1; // error state
        }
        
        return returnState;
}
    
int motorDriverSabertooth::stop(){
        int returnState = 0;
        buffer[0] = 0;
        if(write(serialDevice,buffer,1) != 1){
		printf("Cannot write to motor module \n\r");
		returnState = 1; // error state
        }
        
        return returnState;
}

/*
int main(){
        motorDriverSabertooth driver("/dev/ttyAMA0");
        int8_t left = 0;
        int8_t right = 0;
        while(true){
            driver.setMotorPower(left,right);
            usleep(200000);
        }
}
*/
