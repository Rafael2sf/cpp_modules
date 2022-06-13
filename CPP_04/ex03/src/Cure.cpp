#include "Cure.hpp"

Cure::Cure( void )
{
	(this->_type) = "cure";
}

Cure::~Cure()
{}

Cure::Cure( Cure const & ref )
{
	(void)ref;
	this->_type = "cure";
}

Cure & Cure::operator=( Cure const & rhs )
{
	(void)rhs;
	return (*this);
}

AMateria *Cure::clone( void ) const
{
	return (new Cure());
}

void Cure::use( ICharacter & target )
{
	std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}
