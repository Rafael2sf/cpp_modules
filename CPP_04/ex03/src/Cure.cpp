#include "Cure.hpp"

Cure::Cure( void )
{
	(this->_type) = "cure";
	std::cout << "added Cure magic" << std::endl;
}

Cure::~Cure()
{
	std::cout << "removed Cure magic" << std::endl;
}

Cure::Cure( Cure const & ref )
{
	this->_type = "cure";
	*this = ref;
}

Cure & Cure::operator=( Cure const & rhs )
{
	std::cout << "copied " << rhs._type << " materia" << std::endl;
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
