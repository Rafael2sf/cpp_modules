#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
		scav_a.attack("someone");
		scav_a.GuardGate();
	}
	std::cout << std::endl << std::endl;
	{
		FragTrap frag_a("SC4V-TP");
		frag_a.attack("something");

		FragTrap frag_b(frag_a);
		frag_b.takeDamage(50);
		frag_b.attack("something");
		frag_b.beRepaired(0);
		frag_b.highFivesGuys();

		frag_b.takeDamage(50);
		frag_b.attack("something");
		frag_b.beRepaired(50);
		frag_b.highFivesGuys();

		std::cout << std::endl << std::endl;

		for (int i = 0; i < 100; i++)
			frag_a.beRepaired(0);
		frag_a.attack("something");

		std::cout << std::endl << std::endl;

		FragTrap frag_c = frag_a;
		frag_c.beRepaired(5);
		frag_c.highFivesGuys();
	}
	return (0);
}
