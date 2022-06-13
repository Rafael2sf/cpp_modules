#include <iostream>
#include "Array.tpp"
#include <iomanip>
#include <stdlib.h>

#define MAX_VAL 750
int main(int, char**)
{
	{
		std::cout << std::fixed << std::setprecision(2);
		Array<int> arr;
		std::cout << "empty array size = " << arr.size() << std::endl;
		{
			Array<int>a(10);
			int len = a.size();
			std::cout << "size = " << a.size() << std::endl;
			std::cout << "<int>[ ";
			for (int i = 0; i < len ; i++)
				a[i] = i;
			for (int i = 0; i < len ; i++)
				std::cout << a[i] << " ";
			std::cout << "]" << std::endl;
		}
		std::cout << std::endl;
		{
			Array<float>a(5);
			int len = a.size();
			std::cout << "size = " << a.size() << std::endl;
			std::cout << "<float>[ ";
			for (int i = 0; i < len ; i++)
				a[i] = i * 2;
			for (int i = 0; i < len ; i++)
				std::cout << a[i] << " ";
			std::cout << "]" << std::endl;
		}
		std::cout << std::endl;
		{
			Array<std::string>a(3);
			int len = a.size();
			std::cout << "size = " << a.size() << std::endl;
			std::cout << "<string>[ ";
			a[0] = "Hello";
			a[1] = "World";
			a[2] = "42!";
			for (int i = 0; i < len ; i++)
				std::cout << a[i] << " ";
			std::cout << "]" << std::endl;
		}
	}
	std::cout << std::endl;
	{
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;//
	}
	return 0;
}
