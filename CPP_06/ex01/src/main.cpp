#include "Data.hpp"

int	main( void )
{
	{
		Data test(5);
		Data *datap;

		std::cout << test.getX() << std::endl;
		datap = deserialize(serialize(&test));
		std::cout << datap->getX() << std::endl;
	}
	{
		Data test(2);
		Data *datap;

		std::cout << test.getX() << std::endl;
		datap = deserialize(serialize(&test));
		std::cout << datap->getX() << std::endl;
	}
	{
		Data test(10);
		Data *datap;

		std::cout << test.getX() << std::endl;
		datap = deserialize(serialize(&test));
		std::cout << datap->getX() << std::endl;
	}
	return (0);
}
