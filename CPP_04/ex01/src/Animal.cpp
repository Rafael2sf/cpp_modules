#include "Animal.hpp"

Animal::~Animal()
{
	std::cout << "Animal died" << std::endl;
}

Animal::Animal( void )
{
	this->_type = "Unknown";
	std::cout << "Animal born" << std::endl;
}

Animal::Animal( Animal const & ref )
{
	std::cout << "Animal cloned" << std::endl;
	*this = ref;
}

Animal & Animal::operator=( Animal const & ref )
{
	this->_type = ref._type;
	return ( *this );
}

void Animal::makeSound( void ) const
{
	std::cout << "** unrecognizable animal noises **" << std::endl;
}

std::string Animal::getType( void ) const
{
	return (this->_type);
}
