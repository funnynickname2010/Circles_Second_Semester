#include "Circle.h"

const long double Circle::CircleMyPi = 3.14159265358979323851;

Circle::Circle()
{
	coord_x = 0;
	coord_y = 0;
	radius = 1;
}

Circle::Circle(double x, double y, double r)
{
	coord_x = x;
	coord_y = y;
	radius = r;
}

void Circle::CircleSet(double x, double y, double r)
{
	coord_x = x;
	coord_y = y;
	radius = r;
}

double Circle::CircleLen()
{
	return (2 * CircleMyPi * radius); //Check brackets
}

double Circle::CircleArea()
{
	return (CircleMyPi * (radius * radius));
}

bool Circle::operator <(Circle& obj2)
{
	return (this->CircleArea() < obj2.CircleArea());
}

bool Circle::operator >(Circle& obj2)
{
	return (this->CircleArea() > obj2.CircleArea());
}

bool Circle::operator ==(Circle& obj2)
{
	return (this->CircleArea() == obj2.CircleArea());
}

double Circle::CircleDistance(Circle obj2)
{
	return sqrt(pow(fabs(coord_x - obj2.coord_x), 2) + pow(fabs(coord_y - obj2.coord_y), 2));
}

bool Circle::CircleIntersect(const Circle& obj2)
{
	bool result;

	if ((fabs(radius - obj2.radius) < 0.0000001) && (CircleDistance(obj2) < 0.0000001))
	{
		result = 0;
	}
	else
	{
		result = ((fabs(radius - obj2.radius) < CircleDistance(obj2)) && (CircleDistance(obj2) < (radius + obj2.radius)));
	}

	return result;
}

bool Circle::InCircle(double x, double y)
{
	return ((coord_x - x) * (coord_x - x) + (coord_y - y) * (coord_y - y) <= (radius * radius));
}
