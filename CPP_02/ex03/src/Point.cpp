#include "Point.hpp"

Point::~Point( void )
{}

Point::Point( void ): _x(0), _y(0)
{}

Point::Point( float const x, float const y ): _x(x), _y(y)
{}

Point::Point( Point const & ref )
{
	*this = ref;
}

Point & Point::operator=(Point const & ref)
{
	Fixed	*x = const_cast <Fixed *> (&this->_x);
	Fixed	*y = const_cast <Fixed *> (&this->_y);
	*x = ref._x;
	*y = ref._y;
	return (*this);
}

Fixed const	Point::getX( void ) const
{
	return (this->_x);
}

Fixed const	Point::getY( void ) const
{
	return (this->_y);
}

std::ostream & operator<<( std::ostream & o, Point const & p )
{
	return (o << "(" << p.getX() << ", " << p.getY() << ")");
}
