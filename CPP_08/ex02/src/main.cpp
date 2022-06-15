#include <iostream>
#include "MutantStack.hpp"

int	main( void )
{
	MutantStack<int> mstk;
	mstk.push(42);
	mstk.push(56);
	mstk.push(79);

	std:: cout << mstk[1] << std::endl;
	MutantStack<int>::iterator it = mstk.begin();
	std::cout << *it << std::endl;
	return ( 0 );
}
