#include "Fixed.hpp"

Fixed::Fixed( void ): _exp(0)
{}

Fixed::~Fixed()
{}

Fixed::Fixed( int const & ref )
{
	(this->_exp) = (ref << this->_man);
}

Fixed::Fixed( float const & ref )
{
	(this->_exp) = roundf(ref * (float)(1 << this->_man));
}

Fixed::Fixed( Fixed const & ref )
{
	(this->_exp) = ref.getRawBits();
}

Fixed & Fixed::operator=( Fixed const & ref )
{
	(this->_exp) = ref.getRawBits();
	return (*this);
}

std::ostream & operator<<( std::ostream & o, Fixed const & ref )
{
	o << (ref.getRawBits() >> 8);
	o << '.';
	o << ((ref.getRawBits() & 0x000000FF) * 10000) / 256;
	return (o);
}

int Fixed::getRawBits( void ) const
{
	return (this->_exp);
}

void Fixed::setRawBits( int const raw )
{
	(this->_exp) = raw;
}

float Fixed::toFloat( void ) const
{
	return ((float)this->_exp / (float)(1 << this->_man));
}

int Fixed::toInt( void ) const
{
	return (this->_exp >> this->_man);
}

int const Fixed::_man = 8;
