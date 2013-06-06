#include "vectorMap.h"

#define _USE_MATH_DEFINES

#include <math.h>
#include <limits>
using namespace vm;

bool VectorMap::isInWall(Wall wall,Point point){
	if((std::min(wall.begin.x, wall.end.x) <= point.x) && (point.x <= std::max(wall.begin.x,wall.end.x))){
		if((std::min(wall.begin.y, wall.end.y) <= point.y) && (point.y <= std::max(wall.begin.y,wall.end.y))){
			return true;
		}
	}

	return false;
}

Point VectorMap::getIntersection(Wall wall, State state){
	unsigned int lineState = 0;

	// TODO: change 
	//lineState |= (abs(abs(state.angle  M_PI) - M_PI_2) < std::numeric_limits<double>::epsilon()); // atan isn´t define for this value
	lineState |= (abs(wall.begin.x - wall.end.x) < std::numeric_limits<double>::epsilon()) << 1; // wall is only in x direction
		
	Point intersection;
	switch(lineState){
	case 0:{
		double alpha_1 = tan(state.angle);
		double alpha_2 = (wall.begin.y - wall.end.y) / (wall.begin.x - wall.end.x) ;

		double alphaDiff = alpha_1 - alpha_2;

		if(abs(alphaDiff) < std::numeric_limits<double>::epsilon()){
			// infinite
			goto infinite;
		}

		double b_1 = state.y - alpha_1*state.x;
		double b_2 = wall.begin.y - alpha_2*wall.begin.x;

		intersection.x = (b_2 - b_1) / alphaDiff;
		intersection.y = (alpha_1*b_2 - alpha_2*b_1) / alphaDiff;

		break;
			}
	case 1:{
		double alpha_2 = (wall.begin.y - wall.end.y) / (wall.begin.x - wall.end.x) ;
		double b_2 = wall.begin.y - alpha_2*wall.begin.x;

		intersection.x = state.x;
		intersection.y = alpha_2*state.x + b_2;

		break;
		   }
	case 2:{

		double alpha_1 = tan(state.angle);
		double b_1 = state.y - alpha_1*state.x;

		intersection.x = wall.begin.x;
		intersection.y = alpha_1*wall.begin.x + b_1;

		break;
		   }
	case 3:{

infinite:
		intersection.x = std::numeric_limits<double>::max();
		intersection.y = std::numeric_limits<double>::max();

		break;
		   }
	}

	if(!isInWall(wall,intersection)){
		intersection.x = std::numeric_limits<double>::max();
		intersection.y = std::numeric_limits<double>::max();
	}

	return intersection;
}

void VectorMap::addWall(Wall wall){
	walls.push_back(wall);
}

double VectorMap::getNereastDistToWall(Point point, double angle){
	double nearestDistToWall = -1;
	for(wallIt wall = getWallsItBegin(); wall != getWallsItEnd(); wall++){
		
	}

	return nearestDistToWall;
}

wallIt VectorMap::getWallsItBegin(){
	return walls.begin();
}

wallIt VectorMap::getWallsItEnd(){
	return walls.end();
}