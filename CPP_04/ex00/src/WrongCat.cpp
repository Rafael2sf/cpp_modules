#include "WrongCat.hpp"

WrongCat::WrongCat( void )
{
	this->_type = "Cat";
	std::cout << "It's a " << this->_type << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Good bye, little cow" << std::endl;
}

WrongCat::WrongCat( WrongCat const & ref )
{
	*this = ref;
}

WrongCat & WrongCat::operator=( WrongCat const & ref )
{
	this->_type = ref._type;
	return ( *this );
}

void WrongCat::makeSound( void ) const
{
	std::cout << "** meow meow **" << std::endl;
}

std::string WrongCat::getType( void ) const
{
	return (this->_type);
}
