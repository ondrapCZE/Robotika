/*
	Author: Ondrej Pilat
	Date: 8/10/2012
	Web: ondrap.cz
	Mail: ondrap@ondrap.cz
*/

#include "serialPort.h"
#include <iostream>
#include <sstream>
#ifdef UNIX
#include <stdlib.h>
#endif

serialPort_CLASS::~serialPort_CLASS(){
#ifdef WIN
	CloseHandle(serialPort);
#else
#ifdef UNIX
	close(serialPort);
#endif
#endif
}

bool serialPort_CLASS::connect(string SerialPort){
#ifdef WIN // connect on Windows
	serialPort = CreateFile(
		SerialPort.c_str(),
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		0,
		NULL
	);
	
	if(serialPort==INVALID_HANDLE_VALUE){ // test jestli se povedlo otevrit seriovou linku
		if(GetLastError()==ERROR_FILE_NOT_FOUND){ //serial port does not exist. Inform user.
			cerr << "Neexistujici seriovy port" << endl;
		}else{
			cerr << "Chyba pri otvirani seriove linky" << endl;
		}
		return false;
	}
	
	cout << "Seriovy port " << SerialPort << " otevren " << endl;
	DCB dcbSerialParams = {0};

	if (!GetCommState(serialPort,&dcbSerialParams)) // ziskani nastaveni seriove linky
		return false;

	dcbSerialParams.BaudRate = BAUDRATE_SET;
	dcbSerialParams.ByteSize = 8; //8 data bits
	dcbSerialParams.Parity = NOPARITY; //no parity
	dcbSerialParams.StopBits = ONESTOPBIT; //1 stop

	if (!SetCommState(serialPort,&dcbSerialParams)) // zapis noveho nastaveni seriove linky
		return false;

	cout << "Nastaveny parametry serioveho portu" << endl;

	return true;
#else
#ifdef UNIX
	cout << SerialPort.c_str() << endl;
	serialPort = open(SerialPort.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);

	if(serialPort == -1){
		cerr << "Chyba pri otvirani seriove linky" << endl;
		return false;
	}else{
		cout << "Seriovy port " << SerialPort << " otevren " << endl;
		fcntl(serialPort, F_SETFL, 0);
	}

	termios termiosSerialParams;

	tcgetattr(serialPort,&termiosSerialParams);

	termiosSerialParams.c_cflag &= ~PARENB;
	termiosSerialParams.c_cflag &= ~CSTOPB;
	termiosSerialParams.c_cflag &= ~CSIZE;
	termiosSerialParams.c_cflag |= CS8;

	cfsetispeed(&termiosSerialParams, BAUDRATE_SET);
	cfsetospeed(&termiosSerialParams, BAUDRATE_SET);

	termiosSerialParams.c_cflag |= (CLOCAL | CREAD);

	tcsetattr(serialPort, TCSANOW, &termiosSerialParams);
	cout << "Nastaveny parametry serioveho portu" << endl;

	return true;
#endif
#endif
}

string serialPort_CLASS::readSerial(){
	char buffer[BUFFER_SIZE] = {0};

#ifdef WIN
	DWORD dwBytesRead = 0;
	if(!ReadFile(serialPort,&buffer,BUFFER_SIZE,&dwBytesRead,NULL)){
		cerr << "Nepovedlo se cteni ze serioveho portu" << endl;
		return "";
	}

	string returnString = "";
	
	returnString.append((char*) &buffer,dwBytesRead);
	//for(unsigned int i=0; i < dwBytesRead; ++i)
	//	returnString += buffer[i];
		
	return returnString;
#else
#ifdef UNIX
	unsigned int nread = read(serialPort, &buffer, BUFFER_SIZE);

	string returnString = "";
	
	for(unsigned int i=0; i < nread; ++i)
		returnString += buffer[i];

	return returnString;
#endif
#endif
}

string parseValue(string &Line){
	int index = Line.find(',');
	string value;

	if(index != -1 && Line.length() > index+1){
		value = Line.substr(0,index);
		Line = Line.substr(index+1);
	}else{
		value = Line;
		Line = "";	
	}

	return value;
}

string getLine(string &In){
	int index = In.find('\n');
	string line = "";

	if(In.length() > index + 1 && index != -1){
		line = In.substr(0,index);
		In = In.substr(index + 1);
	}
	
	return line;
}

string parseLine(string &Line){
	stringstream value;
	value.precision(12);
	string time = "";

	if(parseValue(Line) == "$GPGGA"){
		string temp;

		value << "gps ";
		time = parseValue(Line);
		// sirka
		temp = parseValue(Line);
		value << (atoi(temp.substr(0,2).c_str()) + atof(temp.substr(2).c_str())/60.0) << " ";
		parseValue(Line);
		// delka
		temp = parseValue(Line);
		value << (atoi(temp.substr(0,3).c_str()) + atof(temp.substr(3).c_str())/60.0) << " ";
		parseValue(Line);
		// odchylka
		parseValue(Line);
		parseValue(Line);
		value << parseValue(Line) + " ";
	    value << time + "\n";
	}

	return value.str();
}

string getPosition(string &Temp){
	string position = "";
	string line = getLine(Temp);
	while(line!=""){
		position = parseLine(line);
		if(position != "")
			break;

		line = getLine(Temp);
	}

	return position;
}

int main(){
	serialPort_CLASS test;
	if(!test.connect("/dev/ttyUSB0"))
		return 1;
	
	string temp = test.readSerial();
	while(true){
		while(true){
			string position = getPosition(temp);
			if(position != "")
				cout << position;
			else
				break;
		}

		temp += test.readSerial();
	}

	return 0;
}
