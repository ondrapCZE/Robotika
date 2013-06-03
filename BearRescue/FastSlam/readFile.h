#ifndef READ_FILE_H
#define READ_FILE_H

#include <string>

#include "fastSlam.h"

using namespace std;

class readDataFromFile_CLASS{
	FastSLAM_CLASS *mcl;
public:
	readDataFromFile_CLASS(FastSLAM_CLASS* MCL){mcl = MCL;};
	bool startReadFromFile(string File);
};

#endif
