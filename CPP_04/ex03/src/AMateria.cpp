#include "AMateria.hpp"

AMateria::AMateria( void )
{
	std::cout << "new materia" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "lost materia" << std::endl;
}

AMateria::AMateria( AMateria const & ref )
{
	*this = ref;
}

AMateria & AMateria::operator=( AMateria const & ref )
{
	(void)ref;
	std::cout << "copied materia" << std::endl;
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
