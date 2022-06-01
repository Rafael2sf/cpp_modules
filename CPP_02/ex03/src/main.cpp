#include <iostream>
#include "Point.hpp"

int main(void)
{
	Point a(2, 2);
	Point b(4, 4);
	Point c(4, 2);
	Point p(3.5f, 3);

	std::cout << (bsp(a, b, c, p) ? "true" : "false") << std::endl;
	return 0;
}
