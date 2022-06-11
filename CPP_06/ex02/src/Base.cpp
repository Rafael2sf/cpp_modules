#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{}

Base *	generate(void)
{
	srand(time(NULL));
	switch (rand() % 3)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		default:
			break ;
	}
	return (new C());
}

void	identify(Base* p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << 'A' << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << 'B' << std::endl;
	else
		std::cout << 'C' << std::endl;
}

void	identify(Base& p)
{
	try { dynamic_cast<A &>(p); std::cout << 'A' << std::endl; }
	catch ( std::exception & e0 )
	{
		(void)e0;
		try { dynamic_cast<B &>(p); std::cout << 'B' << std::endl; }
		catch ( std::exception & e1 )
		{
			(void)e1;
			std::cout << 'C' << std::endl;
		}
	}
}
