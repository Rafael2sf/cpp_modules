#include <iostream>
#include "Point.hpp"

int main(void)
{
	Fixed a(0);
	for (int i = 0; i < 32; i++)
	{
		a = Fixed(1) + a * Fixed(2);
		std::cout << a << std::endl;
	}
	std::cout << INT32_MAX * 2 << std::endl;
	//std::cout << (bsp(a, b, c, p) == true ? "true" : "false") << std::endl;
	return 0;
}
