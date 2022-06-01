#include "ScavTrap.hpp"

ScavTrap::~ScavTrap()
{
	if (this->_name != "")
		std::cout << "ScavTrap modules removed from " << this->_name << std::endl;
	else
		std::cout << "ScavTrap modules removed from Claptrap" << std::endl;
}

ScavTrap::ScavTrap( void )
{}

ScavTrap::ScavTrap( ScavTrap const & ref )
{
	std::cout << "ClapTrap upgraded to ScavTrap" << std::endl;
	if (this->_name != "")
		std::cout << this->_name  << " configured with ";
	else
		std::cout << "ScavTrap configured with ";
	std::cout << ref._name << " settings" << std::endl;
	*this = ref;
}

ScavTrap::ScavTrap( std::string const name ): ClapTrap(name)
{
	(this->_hp) = 100;
	(this->_ep) = 50;
	(this->_ad) = 20;
	if (this->_name != "")
		std::cout << "ClapTrap, " << this->_name << ", upgraded with ScavTrap module" << std::endl;
	else
		std::cout << "ClapTrap upgraded with ScavTrap module" << std::endl;
}

ScavTrap & ScavTrap::operator=( ScavTrap const & ref )
{
	this->_name = ref._name;
	this->_hp = ref._hp;
	this->_ep = ref._ep;
	this->_ad = ref._ad;
	return (*this);
}

void ScavTrap::attack( std::string const & target )
{
	if (this->_hp <= 0)
	{
		std::cout << this->_name << " is not responding" << std::endl;
		return ;
	}
	if (this->_ep <= 0)
	{
		std::cout << this->_name << " is out of fuel" << std::endl;
		return ;
	}
	this->_ep--;
	std::cout << this->_name << " attacks " << target;
	std::cout << ", causing " << this->_ad;
	std::cout << " points of damage using Scav Attack" << std::endl;
}

void ScavTrap::GuardGate( void )
{
	if (this->_hp <= 0)
	{
		std::cout << this->_name << " is not responding" << std::endl;
		return ;
	}
	if (this->_ep <= 0)
	{
		std::cout << this->_name << " is out of fuel" << std::endl;
		return ;
	}
	std::cout << this->_name << " is now in Gatekeeper mode" << std::endl;
}
