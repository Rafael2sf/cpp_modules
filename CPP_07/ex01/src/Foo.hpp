#ifndef FOO_HPP
# define FOO_HPP

#include <iostream>

template < typename T >
void foo( int _index, T const & _a )
{
	std::cout << "[" << _index << "]:\t" << _a << std::endl;
}

#endif /* FOO_HP */
