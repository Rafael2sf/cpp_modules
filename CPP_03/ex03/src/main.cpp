#include <iostream>
#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap diam_a("DI4M-TP-21");
	diam_a.whoAmI();
	diam_a.GuardGate();
	diam_a.highFivesGuys();
	diam_a.takeDamage(50);
	diam_a.beRepaired(50);
	diam_a.takeDamage(50);
	diam_a.highFivesGuys();
	diam_a.takeDamage(50);
	diam_a.beRepaired(1);
	DiamondTrap diam_b("DI4M-TP-42");
	for (int i = 0; i < 50; i++)
		diam_b.attack("enemy");
	diam_b.highFivesGuys();
	return (0);
}
