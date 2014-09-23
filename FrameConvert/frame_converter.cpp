#include "frame_converter.hpp"
#include <cmath>
//============= public functions ==========

void FrameConverter::setRotationTranslation(const State global,
		const State relative) {
	global_ = global;
	relative_ = relative;
	rotation_ = relative.theta - global.theta;
}

Position FrameConverter::globalToRelative(const Position position) {
	Position temp = position - global_;
	Position final;
	final.x = cos(rotation_) * temp.x - sin(rotation_) * temp.y;
	final.y = sin(rotation_) * temp.x + cos(rotation_) * temp.y;
	return final + relative_;
}

Position FrameConverter::relativeToGlobal(const Position position) {
	Position temp = position - relative_;
	Position final;
	final.x = cos(rotation_) * temp.x + sin(rotation_) * temp.y;
	final.y = -sin(rotation_) * temp.x + cos(rotation_) * temp.y;
	return final + global_;
}
