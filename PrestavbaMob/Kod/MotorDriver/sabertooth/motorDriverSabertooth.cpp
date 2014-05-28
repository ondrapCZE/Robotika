#include "motorDriverSabertooth.hpp"

#include <stdio.h>
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include <stdlib.h>

#include "../../../../obecne/basic.h"

MotorDriverSabertooth::MotorDriverSabertooth(const std::string device) {
	serialDevice_ = open(device.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);

	if (serialDevice_ < -1) {
		printf("Cannot open serial device: %s \n\r", device.c_str());
		exit(1);
	}

	termios termiosSerialParams;

	tcgetattr(serialDevice_, &termiosSerialParams);

	termiosSerialParams.c_cflag &= ~PARENB;
	termiosSerialParams.c_cflag &= ~CSTOPB;
	termiosSerialParams.c_cflag &= ~CSIZE;
	termiosSerialParams.c_cflag |= CS8;

	cfsetispeed(&termiosSerialParams, BAUDRATE_SET);
	cfsetospeed(&termiosSerialParams, BAUDRATE_SET);

	termiosSerialParams.c_cflag |= (CLOCAL | CREAD);

	tcsetattr(serialDevice_, TCSANOW, &termiosSerialParams);
	
	stop();
}

std::string MotorDriverSabertooth::getName() {
	return "Sabertooth 2x5 motor driver over serial line\n\r";
}

unsigned int MotorDriverSabertooth::getMaxPower() {
	return MAX_POWER;
}

int MotorDriverSabertooth::setMotorsPower(const int left, const int right) {
	return setMotorsPower(motorsPower(left, right));
}

int MotorDriverSabertooth::setMotorsPower(const motorsPower power) {
	int returnState = 0;

	buffer_[0] = rob_fce::valueInRange<int>(power.left, MAX_POWER) + 64;
	buffer_[1] = rob_fce::valueInRange<int>(power.right, MAX_POWER) + 192;
	if (write(serialDevice_, buffer_, 2) != 2) {
		printf("Cannot write to motor module \n\r");
		returnState = 1; // error state
	}

	return returnState;
}

int MotorDriverSabertooth::stop() {
	int returnState = 0;
	buffer_[0] = 0;
	if (write(serialDevice_, buffer_, 1) != 1) {
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
