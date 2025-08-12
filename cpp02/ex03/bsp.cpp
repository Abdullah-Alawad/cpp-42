#include "Point.hpp"

float getArea(float x1, float y1, float x2, float y2, float x3, float y3)
{
	return (std::fabs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float triangle = getArea(a.getX().toFloat(), a.getY().toFloat(),
				b.getX().toFloat(), b.getY().toFloat(), c.getX().toFloat(), c.getY().toFloat());

	float a1 = getArea(point.getX().toFloat(), point.getY().toFloat(),
			a.getX().toFloat(), a.getY().toFloat(), b.getX().toFloat(), b.getY().toFloat());
	
	float a2 = getArea(point.getX().toFloat(), point.getY().toFloat(),
			b.getX().toFloat(), b.getY().toFloat(), c.getX().toFloat(), c.getY().toFloat());

	float a3 = getArea(point.getX().toFloat(), point.getY().toFloat(),
				a.getX().toFloat(), a.getY().toFloat(), c.getX().toFloat(), c.getY().toFloat());
 
	const float EPS = 1e-6;

    // Reject if point is on an edge or outside
	if (a1 <= 0.0f || a2 <= 0.0f || a3 <= 0.0f)
        return false;

    // Check total area match with tolerance
    return fabs((a1 + a2 + a3) - triangle) < EPS;
}
