#include <iostream>
#include "Span.hpp"
#include <stdlib.h>

#define SIZE 42000
int	main( void )
{
	srand(time(NULL));
	{
		std::list<int>	a;
		Span 			b(10);

		try { b.shortestSpan(); } 
		catch ( std::exception & e ) { std::cout << e.what() << std::endl; }
		b.addNumber(-42);
		try { b.longestSpan(); } 
		catch ( std::exception & e ) { std::cout << e.what() << std::endl; }
		for (int i = 0; i < 9; i++)
			a.push_back(rand() % 42);
		b.addNumbers(a.begin(), a.end());

		std::cout << b << std::endl;
		try { b.addNumber(42); } 
		catch ( std::exception & e ) { std::cout << e.what() << std::endl; }
		try { b.addNumbers(a.begin(), a.end()); std::cout << b; } 
		catch ( std::exception & e ) { std::cout << e.what() << std::endl; }
		try { std::cout << "shortestSpan: " << b.shortestSpan() << std::endl; } 
		catch ( std::exception & e ) { std::cout << e.what() << std::endl; }
		try { std::cout << "longestSpan: " << b.longestSpan() << std::endl; }
		 catch ( std::exception & e ) { std::cout << e.what() << std::endl; }
	}
	std::cout << std::endl;
	{
		std::list<int>	a;
		Span 			b(SIZE);

		for (int i = 0; i < SIZE; i++)
		{
			if (i % 2)
				a.push_front(rand());
			else
				a.push_front(rand() * -1);
		}
		b.addNumbers(a.begin(), a.end());
		Span c = b;
		std::cout << "Span size = " << SIZE << std::endl;
		std::cout << "shortestSpan: " << c.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << c.longestSpan() << std::endl;
	}
	return ( 0 );
}
