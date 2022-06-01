#include <iostream>
#include "FragTrap.hpp"

int main(void)
{
	FragTrap frag_a("FR4G-TP-21");
	frag_a.takeDamage(50);
	frag_a.beRepaired(50);
	frag_a.takeDamage(50);
	frag_a.highFivesGuys();
	frag_a.takeDamage(50);
	frag_a.beRepaired(1);
	FragTrap frag_b("FR4G-TP-42");
	for (int i = 0; i < 100; i++)
		frag_b.attack("enemy");
	frag_b.highFivesGuys();
	return (0);
}
