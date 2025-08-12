#include "Point.hpp"

Point::Point(): x(0), y(0) {}
		
Point::Point(const float &forX, const float &forY): x(forX), y(forY) {}

Point::Point(const Point &copy): x(copy.x), y(copy.y) {}
		
Point &Point::operator=(const Point &point)
{
	(void)point;
	return (*this);
}
		
Point::~Point() {}

Fixed Point::getX(void) const
{
	return x;
}

Fixed Point::getY(void) const
{
	return y;
}