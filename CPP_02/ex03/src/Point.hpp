#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class	Point
{
	public:
		Point( void );
		~Point();
		Point( float const , float const );
		Point( Point const & );

		Fixed const	getX( void ) const;
		Fixed const	getY( void ) const;

		Point & operator=(Point const &);

	private:
		Fixed const	_x;
		Fixed const	_y;
};

std::ostream & operator<<( std::ostream & o, Point const & p );
bool bsp(Point & a, Point & b, Point  & c, Point & p);

#endif /* POINT_HPP */
