#include <iostream>
#include "Span.hpp"
#include <stdlib.h>

# define SIZE 10

int	main( void )
{
	Span x(SIZE);

	//std::cout << x.shortestSpan() << std::endl;
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++)
	{
		if (rand() % 2)
			x.addNumber(rand());
		else
			x.addNumber(rand() * -1);
	}
	//x.addNumber(rand());
	Span y = x;
	std::cout << x << std::endl;
	std::cout << y << std::endl;
	
	std::cout << x.shortestSpan() << std::endl;
	std::cout << x.longestSpan() << std::endl;
	return ( 0 );
}
