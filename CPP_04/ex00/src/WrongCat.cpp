#include "WrongCat.hpp"

WrongCat::WrongCat( void )
{
	this->_type = "WrongCat";
	std::cout << "It's a " << this->_type << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Good bye, strange kitty" << std::endl;
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
