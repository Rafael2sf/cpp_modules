#include "ScavTrap.hpp"

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap downgraded to ClapTrap" << std::endl;
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

ScavTrap::ScavTrap( std::string const name )
{
	(this->_name) = name;
	(this->_hp) = 100;
	(this->_ep) = 50;
	(this->_ad) = 20;
	std::cout << "ClapTrap upgraded to ScavTrap as " << this->_name << std::endl;
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
	if (this->_isDead() || this->_isTired())
		return ;
	this->_ep--;
	std::cout << this->_name << " attacks " << target;
	std::cout << ", causing " << this->_ad;
	std::cout << " points of damage" << std::endl;
}

void ScavTrap::GuardGate( void )
{
	if (this->_isDead() || this->_isTired())
		return ;
	std::cout << this->_name << " is now in Gatekeeper mode" << std::endl;
}
