#ifndef VECTOR_MAP_H
#define VECTOR_MAP_H

#include <vector>

namespace vm{

struct Point{
	double x;
	double y;
	Point(double x, double y) : x(x), y(y){};
};

struct Wall{
	Point begin;
	Point end;
	Wall(Point begin, Point end) : begin(begin), end(end) {};
};

typedef std::vector<Wall>::iterator wallIt ;

class VectorMap{
	std::vector<Wall> walls;
public:
	void addWall(Wall wall);
	double getNereastDistToWall(Point point, double angle);
	wallIt getWallsItBegin();
	wallIt getWallsItEnd();
};

}
#endif