#include "frame_converter.hpp"
#include <cmath>
#include <iostream>
//============= public functions ==========

Position FrameConverter::rotatePosition(const Position position, const double angle){
	Position temp;
	temp.x = cos(angle) * position.x - sin(angle)*position.y;
	temp.y = sin(angle) * position.x + cos(angle)*position.y;
	return temp;
}

void FrameConverter::setRotationTranslation(const State global,
		const State relative) {
	// general rotation
	globRelTrans_.theta = relative.theta - global.theta;
	relGlobTrans_.theta = global.theta - relative.theta;

	// compute global to relative transformation
	globRelTrans_ = rotatePosition(relative,-globRelTrans_.theta) - global;
	// compute relative to global transformation
	relGlobTrans_ = rotatePosition(global,-relGlobTrans_.theta) - relative;

	initialized_ = true;
}

Position FrameConverter::globalToRelative(const Position position) {
	return rotatePosition((position + globRelTrans_),globRelTrans_.theta);
}

Position FrameConverter::relativeToGlobal(const Position position) {
	return rotatePosition((position + relGlobTrans_),relGlobTrans_.theta);
}
