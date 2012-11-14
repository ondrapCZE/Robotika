#ifndef SERIAL_PORT_H
#define SERIAL_PORT_H

#define UNIX

#include <string>

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

class serialPort_CLASS{
#ifdef WIN
	HANDLE serialPort;
#else
#ifdef UNIX
	int serialPort;
#endif
#endif
public:
	~serialPort_CLASS();
	bool connect(string SerialPort);
	string readSerial();
};

#endif
