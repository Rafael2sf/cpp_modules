#include "Weapon.hpp"

Weapon::Weapon( void )
{}

Weapon::~Weapon()
{}

std::string & const Weapon::getType( void ) const
{
	return (this->_type);
}

void Weapon::setType( std::string & const weapon )
{
	(this->_type) = weapon;
}
