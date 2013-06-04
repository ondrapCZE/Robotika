#include <iostream>
#include <fstream>

#include "readFile.h"
#include "display.h"

bool readDataFromFile_CLASS::startReadFromFile(string File){
	ifstream file;
	file.open(File.c_str(), ios::in);

	if(!file.is_open())
		return false;

	display_CLASS display;

	while(!file.eof()){
		string descriptor;
		file >> descriptor;

		if(descriptor == "state"){
			position_STR position;
			file >> position.x;
			file >> position.y;
			state_STR state(position);
			file >> state.angle;

			printf("State [%f,%f,%f] \n", state.position.x,state.position.y,state.angle);
			mcl->move(state);
		}else{
			if(descriptor == "laser" ){
				double distanceInMM;
				std::vector<double> laserScan;

				for(int i=0; i < 272; ++i){
					file >> distanceInMM;
					laserScan.push_back(distanceInMM / 1000);
				}

				display.writeMap(mcl->getVectorMap());
				display.writeParticle(mcl->getParticles());
				display.writeMostProbState(mcl->getMostProbabilisticState());
				display.writeLaserScan(laserScan,mcl->getMostProbabilisticState());
				display.displayMap();
			}else{
				//error
			}
		}
	}
	
	file.close();
	return true;
}