#include "Ice.hpp"

Ice::Ice( void )
{
	(this->_type) = "ice";
}

Ice::~Ice()
{}

Ice::Ice( Ice const & ref )
{
	(void)ref;
	(this->_type) = "ice";
}

Ice & Ice::operator=( Ice const & rhs )
{
	(void)rhs;
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
