/*!
*  \brief     Atmega encoder reader class
*  \author    Ondrej Pilat (pilat.ondrej@seznam.cz, ondrap.cz)
*  \version   0.1
*  \date      2013
*/

#ifndef ENCODER_ATMEL_H
#define ENCODER_ATMEL_H

#include <string>
#include <unistd.h>

#include "encoder.hpp"

class EncoderAtmel : public EncoderReader {
	static const unsigned int BUFFER_SIZE = 5;
	static const unsigned int MAX_UINT16 = 65535;
	static const unsigned int MAX_DIFFERENCE = (MAX_UINT16 / 2);

	// I2C description for comunication
	int i2cDevice_;
	Encoders encodersLastState_;
	unsigned char buffer_[BUFFER_SIZE];

	int dealWithEncoderOverflow(const int oldValue, const int newValue);
	int readEncodersToBuffer();
	bool checkBufferValidity(const unsigned int size);
public:
	//! Set decoder modul address and communication device.
	/*! Open communication device with given address.
	 \param I2CDevice communication device absolute path in linux (ussualy something like /dev/i2c-0).
	 \param decoderAddress decoder module address on an I2C bus.
	 */
	EncoderAtmel(const std::string I2CDevice = "/dev/i2c-1", const int decoderAddress = 0x30);
	unsigned int getEncodersResolution();
	Encoders getEncodersState();
	//! Return ticks count difference between last call and actual.
	/*! Use often otherwise it cannot guarantee overflow check.
	 * 	Decoder use only 16bit counters and this counters overflow after
	 * 	something like one turn depends on a gear box on motors.
	 */
	Encoders getChangeOfEncoders();

	//! Close opened communication device.
	~EncoderAtmel() {
		close(i2cDevice_);
	};
};


#endif
