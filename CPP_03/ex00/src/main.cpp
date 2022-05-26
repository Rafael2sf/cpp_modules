#include <iostream>
#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clap_a("CL4P-TP");
	clap_a.attack("something");

	ClapTrap clap_b(clap_a);
	clap_b.takeDamage(5);
	clap_b.takeDamage(5);
	clap_b.attack("something");

	std::cout << std::endl << std::endl;

	for (int i = 0; i < 10; i++)
		clap_a.beRepaired(5);
	clap_a.attack("something");

	std::cout << std::endl << std::endl;
	
	ClapTrap clap_c = clap_a;
	clap_c.beRepaired(5);
	return (0);
}
