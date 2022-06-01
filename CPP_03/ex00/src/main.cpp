#include <iostream>
#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clap_a("CL4P-TP-21");
	clap_a.takeDamage(5);
	clap_a.attack("something");
	clap_a.beRepaired(5);
	clap_a.takeDamage(5);
	clap_a.beRepaired(0);
	clap_a.takeDamage(5);
	clap_a.beRepaired(0);
	ClapTrap clap_b("CL4P-TP-42");
	for (int i = 0; i < 10; i++)
		clap_b.attack("enemy");
	clap_b.attack("something");
	return (0);
}
