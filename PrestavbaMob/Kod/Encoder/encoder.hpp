#ifndef ENCODER_H
#define ENCODER_H

struct Encoders{
	int left;
	int right;
};

class encoderReader {
public:
	virtual unsigned int getEncodersResolution()=0;
	virtual Encoders getEncodersState()=0;
	virtual Encoders getChangeOfEncoders()=0;
};

#endif