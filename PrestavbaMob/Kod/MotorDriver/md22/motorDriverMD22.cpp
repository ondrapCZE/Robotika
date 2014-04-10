#include "motorDriverMD22.hpp"

#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>

#include "../../../../obecne/basic.h"

MotorDriverMD22::MotorDriverMD22(std::string deviceI2C, int driverAddress) {
	// Open I2C bus for read and write operation
	if ((i2cDevice_ = open(deviceI2C.c_str(), O_RDWR)) < 0) {
		printf("Failed to open I2C bus \n");
		exit(1);
	}

	if (ioctl(i2cDevice_, I2C_SLAVE, driverAddress) < 0) {
		printf("Failed to set slave adress \n");
		exit(1);
	}
}

std::string MotorDriverMD22::getName() {
	return "MD22 motor driver over I2C";
}

unsigned int MotorDriverMD22::getMaxPower() {
	return MAX_POWER;
}

int MotorDriverMD22::setDefaultMotorMode() {
	int returnState = 0;

	buffer_[0] = 0;
	buffer_[1] = 0;

	if (write(i2cDevice_, buffer_, 2) != 2) {
		printf("Cannot write to motor module \n\r");
		returnState = 1; // error state
	}

	return returnState;
}

int MotorDriverMD22::setMotorsPower(int left, int right) {
	return setMotorsPower(motorsPower(left, right));
}

int MotorDriverMD22::setMotorsPower(motorsPower power) {
	int returnState = 0;

	buffer_[0] = 1;
	buffer_[1] = basic_robotic_fce::valueInRange<int>(power.left, MAX_POWER) + 128;

	if (write(i2cDevice_, buffer_, 2) != 2) {
		printf("Cannot write to motor module \n\r");
		returnState = 1; // error state
	} else {

		buffer_[0] = 2;
		buffer_[1] = basic_robotic_fce::valueInRange<int>(power.right, MAX_POWER) + 128;

		if (write(i2cDevice_, buffer_, 2) != 2) {
			printf("Cannot write to motor module \n\r");
			returnState = 1; // error state
		}
	}

	return returnState;
}

int MotorDriverMD22::stop() {
	motorsPower speed(0, 0);
	return setMotorsPower(speed);
}
