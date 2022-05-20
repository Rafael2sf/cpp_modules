#include "Fixed.hpp"

Fixed::Fixed( void ): _val(0)
{}

Fixed::~Fixed()
{}

Fixed::Fixed( int const & ref )
{
	(this->_val) = (ref << this->_fbits);
}

Fixed::Fixed( float const & ref )
{
	(this->_val) = roundf(ref * (float)(1 << this->_fbits));
}

Fixed::Fixed( Fixed const & ref )
{
	(this->_val) = ref.getRawBits();
}

Fixed Fixed::operator+( Fixed const & ref )
{
	return (Fixed(this->_val + ref.getRawBits()));
}

Fixed Fixed::operator-( Fixed const & ref )
{
	return (Fixed(this->_val - ref.getRawBits()));
}

Fixed Fixed::operator*( Fixed const & ref )
{
	return (Fixed(this->toFloat() * ref.toFloat()));
}

Fixed Fixed::operator/( Fixed const & ref )
{
	return (Fixed(this->toFloat() / ref.toFloat()));
}

Fixed & Fixed::operator=( Fixed const & ref )
{
	(this->_val) = ref.getRawBits();
	return (*this);
}

Fixed & Fixed::operator++( void )
{
	(this->_val++);
	return (*this);
}

Fixed	Fixed::operator++( int dummy )
{
	( void )dummy;
	Fixed	tmp = (this->toFloat());
	(this->_val++);
	return (tmp);
}

std::ostream & operator<<( std::ostream & o, Fixed const & ref )
{
	/* Manual conversion -- not so precise as converting to float
	o << (ref.getRawBits() >> 8);
	o << '.';
	o << ((ref.getRawBits() & 0xFF) * 1000) / 256;
	*/
	return (o << ref.toFloat());
}

int Fixed::getRawBits( void ) const
{
	return (this->_val);
}

void Fixed::setRawBits( int const raw )
{
	(this->_val) = raw;
}

float Fixed::toFloat( void ) const
{
	return ((float)this->_val / (float)(1 << this->_fbits));
}

int Fixed::toInt( void ) const
{
	return (this->_val >> this->_fbits);
}

int const Fixed::_fbits = 8;
