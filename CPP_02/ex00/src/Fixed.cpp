#include "Fixed.hpp"

Fixed::Fixed( void ): _value(0)
{}

Fixed::~Fixed()
{}

Fixed::Fixed( Fixed const & ref )
{
	(this->_value) = ref.getRawBits();
}

Fixed & Fixed::operator=( Fixed const & ref )
{
	(this->_value) = ref.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	return (this->_value);
}

void Fixed::setRawBits( int const raw )
{
	(this->_value) = raw;
}

int const Fixed::_mantissa = 8;
