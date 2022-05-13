#include "HumanA.hpp"

HumanA::~HumanA()
{}

HumanA::HumanA( std::string const name, Weapon & weapon): _weapon(weapon)
{
	(this->_name) = name;
}

std::string HumanA::getName( void ) const
{
	return (this->_name);
}

void HumanA::setName( std::string name )
{
	(this->_name) = name;
}

std::string HumanA::getType( void ) const
{
	return (this->_weapon.getType());
}

void HumanA::setType( std::string type )
{
	(this->_weapon.setType(type));
}

void HumanA::attack( void ) const
{
	std::cout << (this->_name) << " attacks with their ";
	std::cout << (this->_weapon.getType()) << std::endl;
}
