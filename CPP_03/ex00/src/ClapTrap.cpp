#include "ClapTrap.hpp"

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap recycled into scrap" << std::endl;
}

ClapTrap::ClapTrap( void )
{}

ClapTrap::ClapTrap( ClapTrap const & ref )
{
	std::cout << "ClapTrap built without any configuration" << std::endl;
	*this = ref;
}

ClapTrap::ClapTrap( std::string const name )
{
	(this->_name) = name;
	(this->_hp) = 10;
	(this->_ep) = 10;
	(this->_ad) = 0;
	std::cout << this->_name << ", ClapTrap, built from scratch" << std::endl;
}

ClapTrap & ClapTrap::operator=( ClapTrap const & ref )
{
	this->_name = ref._name;
	this->_hp = ref._hp;
	this->_ep = ref._ep;
	this->_ad = ref._ad;
	return (*this);
}

void ClapTrap::attack( std::string const & target )
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
	std::cout << " points of damage using Scrap Attack" << std::endl;
}

void ClapTrap::takeDamage( unsigned int ammount )
{
	this->_hp -= ammount;
	std::cout << this->_name << " took " << ammount;
	std::cout << " points of damage " << std::endl;
}

void ClapTrap::beRepaired( unsigned int ammount )
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
	this->_hp += ammount;
	std::cout << this->_name << " repaired itself by " << ammount;
	std::cout << " health points " << std::endl;
}
