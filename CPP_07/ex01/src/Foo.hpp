#ifndef FOO_HPP
# define FOO_HPP

#include <iostream>

template < typename T >
void foo( T const & _a )
{
	std::cout << _a << " ";
}

#endif /* FOO_HP */
