#include "FragTrap.hpp"

FragTrap::~FragTrap()
{
	std::cout << "FragTrap downgraded to ClapTrap" << std::endl;
}

FragTrap::FragTrap( void )
{}

FragTrap::FragTrap( FragTrap const & ref )
{
	std::cout << "ClapTrap upgraded to FragTrap" << std::endl;
	if (this->_name != "")
		std::cout << this->_name  << " configured with ";
	else
		std::cout << "FragTrap configured with ";
	std::cout << ref._name << " settings" << std::endl;
	*this = ref;
}

FragTrap::FragTrap( std::string const name )
{
	(this->_name) = name;
	(this->_hp) = 100;
	(this->_ep) = 100;
	(this->_ad) = 30;
	std::cout << "ClapTrap upgraded to FragTrap as " << this->_name << std::endl;
}

FragTrap & FragTrap::operator=( FragTrap const & ref )
{
	this->_name = ref._name;
	this->_hp = ref._hp;
	this->_ep = ref._ep;
	this->_ad = ref._ad;
	return (*this);
}

void FragTrap::attack( std::string const & target )
{
	if (this->_isDead() || this->_isTired())
		return ;
	this->_ep--;
	std::cout << this->_name << " attacks " << target;
	std::cout << ", causing " << this->_ad;
	std::cout << " points of damage" << std::endl;
}

void FragTrap::highFivesGuys( void )
{
	if (this->_isDead() || this->_isTired())
		return ;
	std::cout << this->_name << " requests positive motorized high fives" << std::endl;
}
