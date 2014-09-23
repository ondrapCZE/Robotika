#ifndef FRAME_CONVERTER_H
#define FRAME_CONVERTER_H

#include "../obecne/basic.h"

class FrameConverter {
	Position global_;
	Position relative_;
	double rotation_;
public:
	void setRotationTranslation(const State global, const State relative);
	Position globalToRelative(const Position position);
	Position relativeToGlobal(const Position position);
};

#endif
