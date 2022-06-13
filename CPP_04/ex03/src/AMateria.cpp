#include "AMateria.hpp"

AMateria::AMateria( void )
{}

AMateria::~AMateria()
{}

AMateria::AMateria( AMateria const & ref )
{
	*this = ref;
}

AMateria & AMateria::operator=( AMateria const & ref )
{
	(void)ref;
	return (*this);
}

AMateria::AMateria( std::string const & type )
{
	( void )type;
}

std::string const & AMateria::getType( void ) const
{
	return (this->_type);
}

void AMateria::use( ICharacter & target )
{
	std::cout << "* nothing hapens to " << target.getName() << " *" << std::endl;
}
