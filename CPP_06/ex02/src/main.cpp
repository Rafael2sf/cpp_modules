#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main( void )
{
	Base *a = generate();
	std::cout << "identify pointer = ";
	identify(a);
	std::cout << std::endl;
	std::cout << "identify reference * = ";
	identify(*a);
	std::cout << std::endl;
	delete a;
	return (0);
}
