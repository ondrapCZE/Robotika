#ifndef FRAME_CONVERTER_H
#define FRAME_CONVERTER_H

#include "../obecne/basic.h"

class FrameConverter {
	State globRelTrans_;
	State relGlobTrans_;

	bool initialized_;
	Position rotatePosition(const Position position, const double angle);
public:
	FrameConverter(){initialized_ = false;};
	void setRotationTranslation(const State global, const State relative);
	Position globalToRelative(const Position position);
	Position relativeToGlobal(const Position position);
	bool isInitialized(){ return initialized_;};
};

#endif
