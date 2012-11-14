/*
	Author: Ondrej Pilat
	Date: 8/10/2012
	Web: ondrap.cz
	Mail: ondrap@ondrap.cz
*/

#ifndef SERIAL_PORT_H
#define SERIAL_PORT_H

#include <string>

#define WIN

using namespace std;

#define BUFFER_SIZE 32

#ifdef WIN
	#include "Windows.h" /* Windows standard function definitions */
	#define BAUDRATE_SET CBR_115200
#else
#ifdef UNIX
	#include <unistd.h>  /* UNIX standard function definitions */
    #include <fcntl.h>   /* File control definitions */
    #include <errno.h>   /* Error number definitions */
    #include <termios.h> /* POSIX terminal control definitions */
	#define BAUDRATE_SET B115200
#endif
#endif

struct GPSData{ 
	GPSData(double Lat = 0, double Lon = 0, double Acc = 0){latitude = Lat; longitude = Lon; accuracy = Acc;};

	double latitude;
	double longitude;
	double accuracy; // accurancy in metres
};

class serialPort_CLASS{
#ifdef WIN
	HANDLE serialPort;
#else
#ifdef UNIX
	int serialPort;
#endif
#endif

	string rawDataSerial;
	string readSerial();
public:
	~serialPort_CLASS();

	struct GPSData getGPS();
	bool connect(string SerialPort);
};

#endif
