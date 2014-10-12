/*! 
 *  \brief     Atmega encoder reader funtion implementation 
 *  \author    Ondrej Pilat (pilat.ondrej@seznam.cz, ondrap.cz)
 *  \version   0.1
 *  \date      2013
 */

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

int EncoderAtmel::dealWithEncoderOverflow(const int oldValue, const int newValue) {
	int difference = newValue - oldValue;

	if (abs(difference) < MAX_DIFFERENCE) { // overflow test
		return difference;
	} else { // overflow
		if (difference < 0) { // top overflow
			return MAX_UINT16 + difference;
		} else { // bottom overflow
			return difference - MAX_UINT16;
		}
	}
}

int EncoderAtmel::readEncodersToBuffer() {
	int state = 0;
	buffer_[0] = 10; // send command for reading encoders value from decoder
	if (write(i2cDevice_, buffer_, 1) != 1) {
		printf("Failed to write to the i2c bus. \n\r");
		state = 1;
	} else {
		if (read(i2cDevice_, buffer_, 5) != 5) {
			printf("Failed to read from the i2c bus. \n\r");
			state = 1;
		}
	}

	return state;
}

bool EncoderAtmel::checkBufferValidity(const unsigned int size) {
	uint8_t crc = 0;
	for (uint8_t i = 0; i < size; ++i) {
		crc = rob_fce::crc8(crc, buffer_[i]);
	}


	/*if (crc) {
		printf("Damaged data wrong crc \n");
	}*/
	return !crc;
}

EncoderAtmel::EncoderAtmel(const std::string I2CDevice, const int decoderAddress) {
	// Open I2C bus for read and write operation
	if ((i2cDevice_ = open(I2CDevice.c_str(), O_RDWR)) < 0) {
		printf("Failed to open bus \n");
		exit(1);
	}

	if (ioctl(i2cDevice_, I2C_SLAVE, decoderAddress) < 0) {
		printf("Failed to set decoder address bus \n");
		exit(1);
	}

	encodersLastState_ = getEncodersState();
}

unsigned int EncoderAtmel::getEncodersResolution() {
	return 1024; // encoders have 10bit resolution
}

Encoders EncoderAtmel::getEncodersState() {
	bool error, crcCheck;
	do {
		error = readEncodersToBuffer();
		if (!error) {
			crcCheck = checkBufferValidity(5);
		}
	} while (error || !crcCheck);

	Encoders encodersState;
	encodersState.right = buffer_[0] | (buffer_[1] << 8);
	encodersState.left = buffer_[2] | (buffer_[3] << 8);

	//printf("Encoders [%i,%i] \n\r", encodersState.left, encodersState.right);
	return encodersState;
}

Encoders EncoderAtmel::getChangeOfEncoders() {
	Encoders newState = getEncodersState();
	Encoders encodersDifference;

	encodersDifference.left = dealWithEncoderOverflow(encodersLastState_.left, newState.left);
	encodersDifference.right = dealWithEncoderOverflow(encodersLastState_.right, newState.right);

	encodersLastState_ = newState;
	return encodersDifference;
}
