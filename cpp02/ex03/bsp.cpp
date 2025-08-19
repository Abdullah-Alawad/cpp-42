#include "Point.hpp"

Fixed getArea(Point const a, Point const b, Point const c)
{
	int val =	std::abs(a.getX().getRawBits() * (b.getY().getRawBits() - c.getY().getRawBits())
				+ b.getX().getRawBits() * (c.getY().getRawBits() - a.getY().getRawBits())
				+ c.getX().getRawBits() * (a.getY().getRawBits() - b.getY().getRawBits()));
	Fixed res;
	res.setRawBits(val);
	return (res);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed triangle = getArea(a, b, c);
	Fixed a1 = getArea(point, a, b);
	Fixed a2 = getArea(point, b, c);
	Fixed a3 = getArea(point, a, c);

	if (a1.getRawBits() <= 0 || a2.getRawBits() <= 0 || a3.getRawBits() <= 0)
		return false;
	if ((a1.getRawBits() + a2.getRawBits() + a3.getRawBits()) - triangle.getRawBits() == 0)
		return true;
	return false;
}
 