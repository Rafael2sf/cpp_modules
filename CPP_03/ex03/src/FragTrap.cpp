#include "FragTrap.hpp"

FragTrap::~FragTrap()
{
	if (this->_name != "")
		std::cout << "FragTrap modules removed from " << this->_name << std::endl;
	else
		std::cout << "FragTrap modules removed from Claptrap" << std::endl;
}

FragTrap::FragTrap( void )
{
	std::cout << "Added FragTrap modules" << std::endl;
	(this->_hp) = 100;
	(this->_ad) = 30;
}

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

FragTrap::FragTrap( std::string const name ): ClapTrap(name)
{
	(this->_hp) = 100;
	(this->_ep) = 100;
	(this->_ad) = 30;
	if (this->_name != "")
		std::cout << "ClapTrap, " << this->_name << ", upgraded with FragTrap module" << std::endl;
	else
		std::cout << "ClapTrap upgraded with FragTrap module" << std::endl;
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
	std::cout << " points of damage usng Frag Attack" << std::endl;
}

void FragTrap::highFivesGuys( void )
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
	std::cout << this->_name << " requests positive motorized high fives" << std::endl;
}
