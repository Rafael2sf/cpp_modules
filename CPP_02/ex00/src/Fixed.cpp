#include "Fixed.hpp"

Fixed::Fixed( void ): _val(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( Fixed const & ref )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = ref;
}

Fixed & Fixed::operator=( Fixed const & ref )
{
	std::cout << "Copy assignemnt operator called" << std::endl;
	(this->_val) = ref.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_val);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawbits member function called" << std::endl;
	(this->_val) = raw;
}

int const Fixed::_bits = 8;
