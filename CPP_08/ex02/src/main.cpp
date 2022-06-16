#include <iostream>
#include "MutantStack.hpp"
#include <list>
#include <deque>

int main( void )
{
	std::deque<int>::iterator t;
	{
		MutantStack<std::string> stack1;
		stack1.push("1");
		stack1.push("2");
		stack1.push("3");

		std::cout <<"iterator: ";
		for (MutantStack<std::string>::iterator it = stack1.begin(); it != stack1.end(); it++)
			std::cout << *it << " ";


		std::cout << std::endl;
		std::cout <<"reverse_iterator: ";
		for (MutantStack<std::string>::reverse_iterator it = stack1.rbegin(); it != stack1.rend(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		MutantStack<std::string> stack2(stack1);

		std::cout <<"const_iterator: ";
		for (MutantStack<std::string>::const_iterator it = stack2.begin(); it != stack2.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		stack2 = stack1;

		std::cout <<"const_reverse_iterator: ";
		for (MutantStack<std::string>::const_reverse_iterator it = stack2.rbegin(); it != stack2.rend(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	return (0);
}
