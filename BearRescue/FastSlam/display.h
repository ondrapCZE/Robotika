#ifndef DISPLAY_H
#define DISPLAY_H

#include "fastSlam.h"
#include "vectorMap.h"

#include <opencv/cv.h>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>

static const unsigned int HEIGHT = 640;
static const unsigned int WIDTH = 480;

class display_CLASS{
	//display
	cv::Mat map;
	double zoom;
	double shiftX;
	double shiftY;

	float MULTI_STEP;
	int SHIFT_X_STEP;
	int SHIFT_Y_STEP;

	//string windowName;
	//VideoWriter video;
	std::string windowName;
	int fixHeight(int MaxHeight,int Height);
public:
	display_CLASS();
	void display_CLASS::writeMap(vm::VectorMap* VectorMap);
	void writeParticle(const std::vector< particle_STR > &Particles);
	void writeMostProbState(const state_STR &State);
	void displayMap();
};

#endif