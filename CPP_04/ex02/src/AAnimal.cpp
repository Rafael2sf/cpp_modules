#include "AAnimal.hpp"

AAnimal::~AAnimal()
{
	std::cout << "Animal died" << std::endl;
}

AAnimal::AAnimal( void )
{
	this->_type = "Unknow";
	std::cout << "Animal born" << std::endl;
}

AAnimal::AAnimal( AAnimal const & ref )
{
	std::cout << "Animal cloned" << std::endl;
	*this = ref;
}

AAnimal & AAnimal::operator=( AAnimal const & ref )
{
	this->_type = ref._type;
	return ( *this );
}

void AAnimal::makeSound( void ) const
{
	std::cout << "** unrecognizable animal noises **" << std::endl;
}

std::string AAnimal::getType( void ) const
{
	return (this->_type);
}
