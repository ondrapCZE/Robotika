#include "frame_converter.hpp"
#include <cmath>
//============= public functions ==========

void FrameConverter::setRotationTranslation(const State global, //TODO: check if correct
		const State relative) {
	translation_ = relative - global;
	rotation_ = relative.theta - global.theta;
	initialized_ = true;
}

Position FrameConverter::globalToRelative(const Position position) {
	Position final;
	final.x = cos(rotation_) * position.x - sin(rotation_) * position.y
			+ translation_.x;
	final.y = sin(rotation_) * position.x + cos(rotation_) * position.y
			+ translation_.y;
	return final;
}

Position FrameConverter::relativeToGlobal(const Position position) {
	Position final;
	final.x = cos(rotation_) * position.x + sin(rotation_) * position.y
			- translation_.x;
	final.y = -sin(rotation_) * position.x + cos(rotation_) * position.y
			- translation_.y;
	return final;
}
