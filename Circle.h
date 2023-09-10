#pragma once
#include <math.h>

class Circle
{
	double coord_x, coord_y;
	double radius;

	static const long double CircleMyPi;

public:

	Circle();
	Circle(double x, double y, double r);

	void CircleSet(double x, double y, double r);
	double CircleDistance(Circle obj2);
	double CircleLen();
	double CircleArea();

	bool CircleIntersect(const Circle& obj2);
	bool InCircle(double x, double y);  //Including borders
};

