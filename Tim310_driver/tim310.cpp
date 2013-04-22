#include "tim310.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <iostream>
#include <sstream>

Tim310_CLASS::Tim310_CLASS(){
	ctx = NULL;
	openedTim = NULL;

	int result = libusb_init(&ctx);
	if (result != 0) {
		ctx = NULL;
		printf("LIBUSB - Initialization failed with the following error code: %i.\n", result);
	}

	/*
	 * Set the verbosity level to 3 as suggested in the documentation.
	 */
	libusb_set_debug(ctx, 3);
}

Tim310_CLASS::~Tim310_CLASS(){
	close();
	libusb_exit(ctx);
}

void Tim310_CLASS::close(){
	if(openedTim !=NULL){
		int result = libusb_release_interface(openedTim, 0);
		if (result != 0) {
			fprintf(stderr, "LIBUSB - Cannot Release Interface\n");
		}
		printf("LIBUSB - Released Interface\n");

		libusb_close(openedTim);
	}
}

bool Tim310_CLASS::open(int Number){
	if(ctx == NULL)
		return false;
	
	ssize_t numberOfResultDevices = 0;

	libusb_device **devices;
	libusb_device *resultDevice = NULL;
	ssize_t numberOfDevices;
	ssize_t numberOfTims = 0;

	/*
	 * Get a list of all USB devices connected.
	 */
	numberOfDevices = libusb_get_device_list(ctx, &devices);
	
	/*
	 * Iterate through the list of the connected USB devices and search for devices with the given vendorID and prodcutID.
	 */
	for (ssize_t i = 0; i < numberOfDevices; i++) {

		struct libusb_device_descriptor desc;
		int result = libusb_get_device_descriptor(devices[i], &desc);
		if (result < 0) {
			fprintf(stderr, "LIBUSB - Failed to get device descriptor");
		}

		if (desc.idVendor == vendorID && desc.idProduct == 0x5001) {
			resultDevice = devices[i];
			if(numberOfTims++ == Number)
				break;
		}
	}

	/*
	 * None of Tims310 is connected.
	 */

	if(resultDevice == NULL){
		libusb_free_device_list(devices, 1);
		return false;
	}
	
	libusb_open(resultDevice,&openedTim);
	if(openedTim == NULL){
		fprintf(stderr,"\nLIBUSB - Cannot open device\n");
		libusb_free_device_list(devices, 1);
		return false;
	}
	
	if (libusb_kernel_driver_active(openedTim, 0) == 1) {
		printf("LIBUSB - Kernel driver active\n");
		if (libusb_detach_kernel_driver(openedTim, 0) == 0) {
			printf("LIBUSB - Kernel driver detached!\n");
		}
	}

	int result = libusb_claim_interface(openedTim, 0);
	if (result < 0) {
		fprintf(stderr, "LIBUSB - Cannot claim interface\n");
	} else {
		printf("LIBUSB - Claimed interface\n");
	}
	
	/*
	 * Free the list of the connected USB devices and decrease the device reference count.
	 */
	libusb_free_device_list(devices, 1);

	return true;
}

std::vector<uint16_t> Tim310_CLASS::readData(){
	std::vector<uint16_t> data;
	int result = 0;

	unsigned char receiveBuffer[bufferSize];

	/*
	 * Write a SOPAS variable read request to the device.
	 */
	
	int actual = 0;
	const char requestScanData[] = { "\x02sRN LMDscandata\x03\0" };
	int requestLength = strlen(requestScanData);
	result = libusb_bulk_transfer(openedTim, (2 | LIBUSB_ENDPOINT_OUT), (unsigned char*) requestScanData, requestLength, &actual, 0);
	if (result != 0 || actual != requestLength) {
		fprintf(stderr, "LIBUSB - Write Error: %i.\n", result);
		return data;
	}

	/*
	 * Read the SOPAS device response with the given timeout.
	 */
	result = libusb_bulk_transfer(openedTim, (1 | LIBUSB_ENDPOINT_IN), receiveBuffer, bufferSize, &actual, timeout);
	if (result != 0) {
		fprintf(stderr, "LIBUSB - Read Error: %i.\n", result);
		return data;
	}

	receiveBuffer[actual] = 0;

	char* rangeData = strstr((char*) receiveBuffer,"DIST1");
	if(rangeData == NULL)
		return data;

	rangeData += 38; // Start measured data
	std::stringstream dataReader(rangeData);
	dataReader << std::setbase(16);
	uint16_t measuredData;

	for(int i = 0; i < 271; ++i){
		dataReader >> measuredData; 
		if(measuredData == 0)
			measuredData = 4000;

		data.push_back(measuredData);
	}

	return data;
}