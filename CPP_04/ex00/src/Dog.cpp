#include "Dog.hpp"

Dog::Dog( void )
{
	this->_type = "Dog";
	std::cout << "It's a " << this->_type << std::endl;
}

Dog::~Dog()
{
	std::cout << "Good bye, dog" << std::endl;
}

Dog::Dog( Dog const & ref )
{
	*this = ref;
}

Dog & Dog::operator=( Dog const & ref )
{
	this->_type = ref._type;
	return ( *this );
}

void Dog::makeSound( void ) const
{
	std::cout << "** woof woof **" << std::endl;
}
