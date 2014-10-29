#ifndef FRAME_CONVERTER_H
#define FRAME_CONVERTER_H

#include "../obecne/basic.h"

class FrameConverter {
	Position translation_;
	double rotation_;

	bool initialized_;
public:
	FrameConverter(){initialized_ = false;};
	void setRotationTranslation(const State global, const State relative);
	Position globalToRelative(const Position position);
	Position relativeToGlobal(const Position position);
	bool isInitialized(){ return initialized_;};
};

#endif
