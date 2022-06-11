#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main( void )
{
	Base *a = generate();
	identify(a);
	identify(*a);
	delete a;
	return (0);
}
