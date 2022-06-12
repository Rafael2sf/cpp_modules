#include "Iter.hpp"
#include "Foo.hpp"
#include <iomanip>

int	main(void)
{
	std::cout << std::fixed << std::setprecision(2);
	int	arr[] = {4, 42, 420 , 24 , 2};

	iter<int>(arr, 5, foo);
	return (0);
}
