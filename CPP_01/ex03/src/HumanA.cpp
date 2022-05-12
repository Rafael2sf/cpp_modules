#include "HumanA.hpp"

HumanA::~HumanA()
{}

HumanA::HumanA( std::string const name, Weapon & weapon): _weapon(weapon)
{
	(this->_name) = name;
}

std::string HumanA::getName( void ) const
{

}

void HumanA::setName( std::string )
{

}

std::string HumanA::getType( void ) const
{

}

void HumanA::setType( std::string )
{

}

void HumanA::attack( void ) const
{}
