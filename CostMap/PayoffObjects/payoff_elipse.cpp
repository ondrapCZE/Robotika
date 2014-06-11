#include "payoff_elipse.hpp"

using namespace costMap;

PayoffElipse::PayoffElipse(const Position center, const float radiusX,
		const float radiusY, const float payoff) :
		center_(center), radiusX_(radiusX), radiusY_(radiusY), payoff_(payoff) {

}

void PayoffElipse::updatePayoffTable(Table table, float resolution) {
	int centerX = center_.x / resolution;
	int centerY = center_.y / resolution;
	int height = radiusY_ / resolution;
	int width = radiusX_ / resolution;

	int hh = height * height;
	int ww = width * width;
	int hhww = hh * ww;
	int x0 = width;
	int dx = 0;

	// do the horizontal diameter
	for (int x = -width; x <= width; x++)
		setTableValue(table,centerX + x, centerY);

	// now do both halves at the same time, away from the diameter
	for (int y = 1; y <= height; y++)
	{
	    int x1 = x0 - (dx - 1);  // try slopes of dx - 1 or more
	    for ( ; x1 > 0; x1--)
	        if (x1*x1*hh + y*y*ww <= hhww)
	            break;
	    dx = x0 - x1;  // current approximation of the slope
	    x0 = x1;

	    for (int x = -x0; x <= x0; x++)
	    {
	    	setTableValue(table,centerX + x, centerY - y);
	    	setTableValue(table,centerX + x, centerY + y);
	    }
	}
}

int PayoffElipse::getMinPayoff() {
	return payoff_;
}
