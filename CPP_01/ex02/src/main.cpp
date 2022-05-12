#include <iostream>

int main(void)
{
	std::string var = "HI THIS IS BRAIN";
	std::string *string_ptr = &var;
	std::string &string_ref = var;

	std::cout << &var << std::endl;
	std::cout << string_ptr << std::endl;
	std::cout << &string_ref << std::endl;
	std::cout << std::endl;
	std::cout << var << std::endl;
	std::cout << *string_ptr << std::endl;
	std::cout << string_ref << std::endl;
}
