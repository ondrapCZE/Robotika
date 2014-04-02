#ifndef MOTOR_DRIVER_MD22_H
#define MOTOR_DRIVER_MD22_H
// int motorsAddress = 0x58 for mob md22

#include "../motorDriver.hpp"
#include <unistd.h>  /* UNIX standard function definitions */

class motorDriverMD22 : public motorDriver {
	static const unsigned int MAX_POWER = 127;
	static const unsigned int BUFFER_SIZE = 3;

	int i2cDevice;
	unsigned char buffer[BUFFER_SIZE];
public:
	motorDriverMD22(std::string deviceI2C, int driverAddress);
	std::string getName();
	unsigned int getMaxPower();

	int setDefaultMotorMode();
	int setMotorsPower(const int left, const int right);
	int setMotorsPower(const motorsPower power);

	int stop();

	~motorDriverMD22() {
		close(i2cDevice);
	};
};

#endif
