#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include "easyfind.hpp"

int	main( void )
{
	{
		std::list<int>		lt;

		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);

		if (easyfind(lt, 1) != lt.end())
			std::cout << "found!" << std::endl; 
		else
			std::cout << "not found!" << std::endl; 
		if (easyfind(lt, 0) != lt.end())
			std::cout << "found!" << std::endl; 
		else
			std::cout << "not found!" << std::endl; 
	}
	{
		std::vector<int> vt;

		vt.push_back(1);
		vt.push_back(2);
		vt.push_back(3);

		if (easyfind(vt, 2) != vt.end())
			std::cout << "found!" << std::endl; 
		else
			std::cout << "not found!" << std::endl; 
		if (easyfind(vt, 5) != vt.end())
			std::cout << "found!" << std::endl; 
		else
			std::cout << "not found!" << std::endl; 
	}
	{
		std::deque<int>	dq;

		dq.push_back(1);
		dq.push_back(2);
		dq.push_back(3);

		if (easyfind(dq, 3) != dq.end())
			std::cout << "found!" << std::endl; 
		else
			std::cout << "not found!" << std::endl; 
		if (easyfind(dq, -1) != dq.end())
			std::cout << "found!" << std::endl; 
		else
			std::cout << "not found!" << std::endl; 
	}
	return ( 0 );
}
