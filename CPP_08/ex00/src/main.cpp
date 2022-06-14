#include <iostream>
#include <algorithm>
#include <list>
#include <deque>
#include <vector>
#include "easyfind.hpp"

int	main( void )
{
	std::list<int>		lt;
	std::vector<int>	vt;
	std::deque<int>		dq;

	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);

	std::cout << easyfind(lt, 1) << std::endl;
	std::cout << easyfind(lt, 0) << std::endl;

	vt.push_back(1);
	vt.push_back(2);
	vt.push_back(3);

	std::cout << easyfind(vt, 2) << std::endl;
	std::cout << easyfind(vt, 5) << std::endl;

	dq.push_back(1);
	dq.push_back(2);
	dq.push_back(3);

	std::cout << easyfind(dq, 3) << std::endl;
	std::cout << easyfind(dq, -1) << std::endl;
	return ( 0 );
}
