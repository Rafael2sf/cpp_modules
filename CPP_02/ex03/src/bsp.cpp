#include "Point.hpp"

/*
static Fixed	triangle_area(Point & p1, Point & p2, Point & p3)
{
	Fixed a = (Fixed((
		((p1.getX() - p2.getX()) * (p1.getY() - p3.getY()))
		- ((p1.getX() - p3.getX()) * (p1.getY() - p2.getY()))
		) / Fixed(2)));
	return (a >= 0 ? a : a * Fixed(-1));
}

bool	bsp(Point & a, Point & b, Point  & c, Point & p)
{
	Fixed	a1, a2, a3;

	if ((p.getX() == a.getX() && p.getY() == a.getY())
	 	|| (p.getX() == b.getX() && p.getY() == b.getY())
		|| (p.getX() == c.getX() && p.getY() == c.getY()))
		return (false);
	a1 = triangle_area(p, a, b);
	a2 = triangle_area(p, b, c);
	a3 = triangle_area(p, c, a);
	if ((a1 + a2 + a3) == triangle_area(a, b, c))
		return (true);
	return (false);
}
*/
