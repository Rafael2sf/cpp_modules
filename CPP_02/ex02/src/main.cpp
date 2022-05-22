#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	std::cout << std::endl;
	{
		Fixed a( Fixed( 10 ) );
		Fixed b = (a * Fixed(1.5f));

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		b = b / 4;
		std::cout << b << std::endl;
		b = Fixed(10.125f);
		std::cout << Fixed::min(a, b) << std::endl;
		std::cout << Fixed::max(a, b) << std::endl;
		std::cout << (a == b ? "true" : "false") << std::endl;
		std::cout << (a != b ? "true" : "false") << std::endl;
		std::cout << (a >= b ? "true" : "false") << std::endl;
		std::cout << (a <= b ? "true" : "false") << std::endl;
		std::cout << (a > b ? "true" : "false") << std::endl;
		std::cout << (a < b ? "true" : "false") << std::endl;
	}
	return 0;
}
