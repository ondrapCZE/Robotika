#ifndef VECTOR_MAP_H
#define VECTOR_MAP_H

#include <vector>
#include "../../obecne/basic.h"

namespace vm{

struct Point{
	double x;
	double y;
	Point(double x = 0, double y = 0) : x(x), y(y){};
};

struct Wall{
	Point begin;
	Point end;
	Wall(Point begin, Point end) : begin(begin), end(end) {};
};

typedef std::vector<Wall>::iterator wallIt ;

class VectorMap{
	std::vector<Wall> walls;
	bool isInWall(Wall wall,Point point);
	bool isInRange(double s, double e, double value);
	double getDistance(Point begin, Point end);
	Point getIntersection(Wall wall, State state);
public:
	void addWall(Wall wall);
	Point getNereastDistToWalls(State state);
	wallIt getWallsItBegin();
	wallIt getWallsItEnd();
};

}
#endif