#ifndef DIFFERENCIAL_CHASSIS_H
#define DIFFERENCIAL_CHASSIS_H

#if !defined __cplusplus || defined __STDC_FORMAT_MACROS

#include <stdint.h>
#include "../../../obecne/basic.h"
#include "../Dekoder/decoder.h"

struct Speed{
	uint8_t left;
	uint8_t right;
};

class DifferencialChassis{
	virtual void setSpeed(struct Speed speed)=0;
	virtual state getState();
	virtual encoders getEncoders();
};

#endif