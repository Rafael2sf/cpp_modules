#include "Cat.hpp"

Cat::Cat( void )
{
	this->_type = "Cat";
	std::cout << "It's a " << this->_type << std::endl;
}

Cat::~Cat()
{
	std::cout << "Good bye, kitty" << std::endl;
}

Cat::Cat( Cat const & ref )
{
	*this = ref;
}

Cat & Cat::operator=( Cat const & ref )
{
	this->_type = ref._type;
	return ( *this );
}

void Cat::makeSound( void ) const
{
	std::cout << "** meow meow **" << std::endl;
}
