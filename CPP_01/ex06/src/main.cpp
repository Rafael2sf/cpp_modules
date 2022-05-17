#include <iostream>
#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl	harl = Harl();
	
	if (argc != 2)
	{
		std::cerr << "Usage: ./harlFilter 'log_level'\n";
		return (1);
	}
	harl.complain(std::string(argv[1]));
	return (0);
}
