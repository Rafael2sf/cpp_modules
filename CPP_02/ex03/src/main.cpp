#include <iostream>
#include "Point.hpp"

int main(void)
{
	Point	a(1, 1);
	Point	b(1, 4);
	Point	c(4, 1);
	Point	p(1, 2);

	std::cout << (bsp(a, b, c, p) == true ? "true" : "false") << std::endl;
	return 0;
}
