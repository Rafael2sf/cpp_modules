#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
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
	}
		std::cout << std::endl << std::endl;
	{
		ScavTrap scav_a("SC4V-TP");
		scav_a.attack("something");

		ScavTrap scav_b(scav_a);
		scav_b.takeDamage(50);
		scav_b.attack("something");
		scav_b.beRepaired(0);
		scav_b.GuardGate();

		scav_b.takeDamage(50);
		scav_b.attack("something");
		scav_b.beRepaired(50);
		scav_b.GuardGate();

		std::cout << std::endl << std::endl;

		for (int i = 0; i < 50; i++)
			scav_a.beRepaired(5);
		scav_a.attack("something");

		std::cout << std::endl << std::endl;

		ScavTrap scav_c = scav_a;
		scav_c.beRepaired(5);
		scav_c.GuardGate();
	}
	return (0);
}
