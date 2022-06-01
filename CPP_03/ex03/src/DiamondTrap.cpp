#include "DiamondTrap.hpp"

DiamondTrap::~DiamondTrap()
{
	std::cout << this->_name << " prepared to be dismantled" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ): ClapTrap(name + "_clap_name")
{
	this->_name = name;
	if (this->_name != "")
		std::cout << "DiamondTrap, " << this->_name << ", creted from merged modules" << std::endl;
	else
		std::cout << "DiamondTrap creted from merged modules" << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const & ref ): FragTrap(ref._name + "_clap_name"), ScavTrap(ref._name + "_clap_name")
{
	this->_name = ref._name;
}

DiamondTrap & DiamondTrap::operator=( DiamondTrap const & )
{
	return (*this);
}

void	DiamondTrap::attack( std::string const & ref )
{
	ScavTrap::attack(ref);
}

void	DiamondTrap::whoAmI( void )
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
	std::cout << "Hello. My name is " << this->_name << " aka " << ClapTrap::_name << std::endl;
}
