#include "Ice.hpp"

Ice::Ice( void )
{
	(this->_type) = "ice";
	std::cout << "added Ice magic" << std::endl;
}

Ice::~Ice()
{
	std::cout << "removed Ice magic" << std::endl;
}

Ice::Ice( Ice const & ref )
{
	this->_type = "ice";
	*this = ref;
}

Ice & Ice::operator=( Ice const & rhs )
{
	std::cout << "copied " << rhs._type << " materia" << std::endl;
	return (*this);
}

AMateria *Ice::clone( void ) const
{
	return (new Ice());
}

void Ice::use( ICharacter & target )
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
