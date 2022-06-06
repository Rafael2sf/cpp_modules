#include "AMateria.hpp"

AMateria::AMateria( void )
{
	;
}

AMateria::~AMateria()
{
	;
}

AMateria::AMateria( AMateria const & )
{
	;
}

AMateria & AMateria::operator=( AMateria const & ref )
{
	( void )ref;
}

AMateria::AMateria( std::string const & type )
{
	( void )type;
}

std::string const & AMateria::getType( void ) const
{
	return ("");
}
