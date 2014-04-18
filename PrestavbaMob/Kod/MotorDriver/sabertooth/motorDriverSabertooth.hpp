#ifndef MOTOR_DRIVER_SABERTOOTH_H
#define MOTOR_DRIVER_SABERTOOTH_H

#include <termios.h> /* POSIX terminal control definitions */
#include <unistd.h>

#include "../motorDriver.hpp"

class MotorDriverSabertooth : public MotorDriver {
	static const unsigned int MAX_POWER = 63;
	static const unsigned int BUFFER_SIZE = 2;
	static const unsigned int BAUDRATE_SET = B38400;

	int serialDevice_;
	unsigned char buffer_[BUFFER_SIZE];
public:
	MotorDriverSabertooth(const std::string device);
	std::string getName();
	unsigned int getMaxPower();

	int setMotorsPower(const int left, const int right);
	int setMotorsPower(const motorsPower power);

	int stop();

	~MotorDriverSabertooth() {
		close(serialDevice_);
	};
};

#endif