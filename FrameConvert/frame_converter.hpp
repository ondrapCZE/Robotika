#ifndef FRAME_CONVERTER_H
#define FRAME_CONVERTER_H

#include "../obecne/basic.h"

class FrameConverter {
	Position translate_;
	double rotate_;
public:
	void setRotationTranslation(const State start, const State target);
	Position convert(const Position position);
};

#endif
