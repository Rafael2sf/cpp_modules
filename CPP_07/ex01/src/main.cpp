#include "Iter.hpp"
#include <iomanip>

template < typename T >
static void foo( T const & _a )
{
	std::cout << _a << " ";
}

int	main(void)
{
	std::cout << std::fixed << std::setprecision(2);
	{
		int	arr[] = {4, 42, 420 , 24 , 2};
		std::cout << "<int> ( ";
		iter<int>(arr, 5, foo);
		std::cout << ")";
	}
	std::cout << std::endl;
	{
		float	arr[] = {1, 2, 3 , 4};
		std::cout << "<float> ( ";
		iter<float>(arr, 4, foo);
		std::cout << ")";
	}
	std::cout << std::endl;
	{
		std::string	arr[] = {"a", "bb", "ccc"};
		std::cout << "<string> ( ";
		iter<std::string>(arr, 3, foo);
		std::cout << ")";
	}
	std::cout << std::endl;
	return (0);
}
