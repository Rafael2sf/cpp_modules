#include "HumanB.hpp"

HumanB::~HumanB()
{}

HumanB::HumanB( std::string name )
{
	(this->_name) = name;
	(this->_weapon) = nullptr;
}

void HumanB::setWeapon ( Weapon & weapon)
{
	(this->_weapon) = &weapon;
}

std::string HumanB::getName( void ) const
{
	return (this->_name);
}

void HumanB::setName( std::string name )
{
	(this->_name) = name;
}

std::string HumanB::getType( void ) const
{
	return (this->_weapon->getType());
}

void HumanB::setType( std::string type )
{
	this->_weapon->setType(type);
}

void HumanB::attack( void ) const
{
	std::cout << (this->_name) << " attacks with their ";
	std::cout << (this->_weapon->getType()) << std::endl;
}
