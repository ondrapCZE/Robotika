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
    
int motorDriverSabertooth::setMotorPower(int8_t left, int8_t right){
    return setMotorPower(SpeedMotors(left,right));
}

int motorDriverSabertooth::setMotorPower(SpeedMotors speed){
        int returnState = 0;
        if(speed.left < -127){
            speed.left = -126;
        }
        
        uint8_t left = (speed.left + 128)/2;
        uint8_t right = (speed.right + 128)/2 + 128;
        
        buffer[0] = left | right;
        if(write(serialDevice,buffer,1) != 1){
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

int main(){
        motorDriverSabertooth driver("/dev/ttyAMA0");
        int8_t left = -128;
        int8_t right = -128;
        while(true){
            driver.setMotorPower(left++,right++);
            usleep(200000);
        }
}
