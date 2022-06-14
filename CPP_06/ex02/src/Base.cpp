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
			std::cout << "Generated: A" << std::endl;
			return (new A());
		case 1:
			std::cout << "Generated: B" << std::endl;
			return (new B());
		default:
			break ;
	}
	std::cout << "Generated: C" << std::endl;
	return (new C());
}

void	identify(Base* p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << 'A';
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << 'B';
	else
		std::cout << 'C';
}

void	identify(Base& p)
{
	try { ( void )dynamic_cast<A &>(p); std::cout << 'A'; }
	catch ( std::exception & e0 )
	{
		(void)e0;
		try { ( void )dynamic_cast<B &>(p); std::cout << 'B'; }
		catch ( std::exception & e1 )
		{
			(void)e1;
			std::cout << 'C';
		}
	}
}
