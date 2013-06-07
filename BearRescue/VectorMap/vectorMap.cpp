#include "vectorMap.h"

#define _USE_MATH_DEFINES

#include <math.h>
#include <limits>
using namespace vm;

static const double EPSILON = 1.0e-10;

// TODO: blbne dava divny vysledky
bool VectorMap::isInWall(Wall wall,Point point){
	if(isInRange(wall.begin.x, wall.end.x, point.x) && isInRange(wall.begin.y, wall.end.y, point.y)){
		return true;
	}else{
		return false;
	}
}

bool VectorMap::isInRange(double s, double e, double value){
	if(s > e){
		double c = s;
		s = e;
		e = c;
	}

	s -= EPSILON;
	e += EPSILON;

	if(s <= value && value <= e){
		return true;
	}else{
		return false;
	}
}

double VectorMap::getDistance(Point begin, Point end){
	return hypot(begin.x - end.x,begin.y - end.y);
}

Point VectorMap::getIntersection(Wall wall, State state){
	double a_wall = wall.end.y - wall.begin.y;
	double b_wall = wall.begin.x - wall.end.x;
	double c_wall = - a_wall*wall.begin.x - b_wall*wall.begin.y;

	double a_state = sin(state.angle);
	double b_state = -cos(state.angle);
	double c_state = - a_state*state.x - b_state*state.y;

	double orthogonal = a_wall * b_state - (-b_wall)*a_state;

	if(abs(orthogonal) > std::numeric_limits<double>::epsilon() ){ // lines have intersection
		Point intersection;
		intersection.y = (a_wall*c_state - a_state*c_wall)/(a_state* b_wall - a_wall * b_state);
		intersection.x = (intersection.y*(b_wall - b_state) + c_wall - c_state)/(a_state - a_wall);
		if(isInWall(wall,intersection)){
			return intersection;
		}
	}
	
	return Point(std::numeric_limits<double>::max(), std::numeric_limits<double>::max());
}

void VectorMap::addWall(Wall wall){
	walls.push_back(wall);
}

Point VectorMap::getNereastDistToWalls(State state){
	double nearestDistToWall = std::numeric_limits<double>::max();
	Point nearestIntersection;
	for(wallIt wall = getWallsItBegin(); wall != getWallsItEnd(); wall++){
		Point intersection = getIntersection((*wall),state);
		if(intersection.x == std::numeric_limits<double>::max())
			continue;

		double distance = std::numeric_limits<double>::max();

		unsigned int cond = 0;
		cond = basic_robotic_fce::normAngle(state.angle) > 0;
		cond |= (intersection.y > state.y) << 1;

		switch(cond){
		case 0: 
		case 3: 
			distance = getDistance(Point(state.x,state.y),intersection);
			break;
		default:
			break;
	
		}

		if(distance < nearestDistToWall){
				nearestDistToWall = distance;
				nearestIntersection = intersection;
		}
	}

	//return nearestDistToWall;
	return nearestIntersection;
}

wallIt VectorMap::getWallsItBegin(){
	return walls.begin();
}

wallIt VectorMap::getWallsItEnd(){
	return walls.end();
}