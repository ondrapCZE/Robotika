#include "frame_converter.hpp"
#include <cmath>
//============= public functions ==========

void FrameConverter::setRotationTranslation(const State start, const State target){
	translate_ = start - target;
	rotate_ = start.theta - target.theta;
}

Position FrameConverter::convert(const Position position){
	Position temp = position + translate_;
	return Position(temp.x*cos(rotate_) + temp.y*sin(rotate_), -temp.x*sin(rotate_) + temp.y*cos(rotate_));
}
