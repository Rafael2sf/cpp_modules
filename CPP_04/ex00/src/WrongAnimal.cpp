#include "WrongAnimal.hpp"

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong animal died" << std::endl;
}

WrongAnimal::WrongAnimal( void )
{
	this->_type = "Wrong";
	std::cout << "Wrong animal born" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const & ref )
{
	*this = ref;
}

WrongAnimal & WrongAnimal::operator=( WrongAnimal const & ref )
{
	this->_type = ref._type;
	return ( *this );
}

void WrongAnimal::makeSound( void ) const
{
	std::cout << "** unrecognizable wrong animal noises **" << std::endl;
}

std::string WrongAnimal::getType( void ) const
{
	return (this->_type);
}
