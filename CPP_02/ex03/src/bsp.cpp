#include "Point.hpp"

static Fixed	pointDistaceFromLine(Point & a, Point & b, Point & p);

bool	bsp(Point & a, Point & b, Point  & c, Point & p)
{
	Fixed d1, d2;

	d1 = pointDistaceFromLine(a, b, p);
	d2 = pointDistaceFromLine(a, b, c);
	if (!((d1 < 0 && d2 < 0) ||	(d1 > 0 && d2 > 0)))
		return ( false );
	d1 = pointDistaceFromLine(b, c, p);
	d2 = pointDistaceFromLine(b, c, a);
	if (!((d1 < 0 && d2 < 0) ||	(d1 > 0 && d2 > 0)))
		return ( false );
	d1 = pointDistaceFromLine(c, a, p);
	d2 = pointDistaceFromLine(c, a, b);
	if (!((d1 < 0 && d2 < 0) ||	(d1 > 0 && d2 > 0)))
		return ( false );
	return ( true );
}

static Fixed	pointDistaceFromLine(Point & a, Point & b, Point & p)
{
	return (
		((p.getX() - a.getX()) * (b.getY() - a.getY()))
		- ((p.getY() - a.getY()) * (b.getX() - a.getX()))
	);
}
