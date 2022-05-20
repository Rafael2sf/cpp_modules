#include <iostream>
#include "Fixed.hpp"

int main(void)
{	
	Fixed a = Fixed(5) + Fixed(2);
	std::cout << a.toFloat();
	return (0);
}
