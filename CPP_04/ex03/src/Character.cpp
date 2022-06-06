#include "Character.hpp"

Character::Character( void )
{
	;
}

Character::~Character()
{
	;
}

Character::Character( Character const & ref )
{
	( void )ref;
}

Character & Character::operator=( Character const & rhs )
{
	( void )rhs;
	return (*this);
}
