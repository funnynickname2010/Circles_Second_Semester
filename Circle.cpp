#include "Circle.h"

const long double Circle::CircleMyPi = 3.14159265358979323851;

Circle::Circle()
{
	coord_x = 0;
	coord_y = 0;
	radius = 0;
}

Circle::Circle(double x, double y, double r)
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

double Circle::CircleDistance(Circle obj2)
{
	return sqrt(pow(abs(coord_x - obj2.coord_x), 2) + pow(abs(coord_y - obj2.coord_y), 2));
}

bool Circle::CircleIntersect(const Circle& obj2)
{
	return (abs(radius - obj2.radius) < CircleDistance(obj2) < (radius + obj2.radius));
}

bool Circle::InCircle(double x, double y)
{
	return ((coord_x - x) * (coord_x - x) + (coord_y - y) * (coord_y - y) <= (radius * radius));
}