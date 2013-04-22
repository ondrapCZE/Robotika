#ifndef TIM310_H
#define TIM310_H

#include <libusb.h>
#include <vector>

class Tim310_CLASS{
	libusb_context* ctx;
	
	static const unsigned int bufferSize = 65536;
	static const int vendorID = 0x19A2; // SICK AG
	static const int deviceID = 0x5001; // TIM3XX
	static const int timeout = 500;

	libusb_device_handle *openedTim;
public:
	Tim310_CLASS();
	~Tim310_CLASS();
	bool open(int Number = 0);
	std::vector<uint16_t> readData();
	void close();
};

#endif