#include <iostream>
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap svav_a("SC4V-TP-21");
	svav_a.GuardGate();
	svav_a.takeDamage(50);
	svav_a.beRepaired(50);
	svav_a.takeDamage(100);
	svav_a.beRepaired(420);
	ScavTrap svav_b("SC4V-TP-42");
	for (int i = 0; i < 50; i++)
		svav_b.attack("enemy");
	svav_b.GuardGate();
	return (0);
}
