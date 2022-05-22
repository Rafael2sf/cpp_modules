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
	*this = ref;
}

Fixed & Fixed::operator=( Fixed const & ref )
{
	(this->_val) = ref.getRawBits();
	return (*this);
}

Fixed Fixed::operator+( Fixed const & ref ) const
{
	Fixed ret = Fixed();
	ret.setRawBits(this->_val + ref.getRawBits());
	return (ret);
}

Fixed Fixed::operator-( Fixed const & ref ) const
{
	Fixed ret = Fixed();
	ret.setRawBits(this->_val - ref.getRawBits());
	return (ret);
}

Fixed Fixed::operator*( Fixed const & ref ) const
{
	Fixed ret = Fixed();
	ret.setRawBits(((long long)this->_val * (long long)ref.getRawBits()) >> this->_fbits);
	return (ret);
}

Fixed Fixed::operator/( Fixed const & ref ) const
{
	Fixed ret = Fixed();
	ret.setRawBits(((long long)this->_val << this->_fbits) / ref.getRawBits());
	return (ret);
}

Fixed & Fixed::operator++( void )
{
	(this->_val++);
	return (*this);
}

Fixed	Fixed::operator++( int dummy )
{
	( void )dummy;
	Fixed	tmp = Fixed(*this);
	(this->_val++);
	return (tmp);
}

Fixed & Fixed::operator--( void )
{
	(this->_val--);
	return (*this);
}

Fixed	Fixed::operator--( int dummy )
{
	( void )dummy;
	Fixed	tmp = Fixed(*this);
	(this->_val--);
	return (tmp);
}

bool	Fixed::operator==( Fixed const & ref ) const
{
	return (this->_val == ref.getRawBits());
}

bool	Fixed::operator!=( Fixed const & ref ) const
{
	return (this->_val != ref.getRawBits());
}

bool	Fixed::operator<( Fixed const & ref ) const
{
	return (this->_val < ref.getRawBits());
}

bool	Fixed::operator>( Fixed const & ref ) const
{
	return (this->_val > ref.getRawBits());
}

bool	Fixed::operator<=( Fixed const & ref ) const
{
	return (this->_val <= ref.getRawBits());
}

bool	Fixed::operator>=( Fixed const & ref ) const
{
	return (this->_val >= ref.getRawBits());
}

std::ostream & operator<<( std::ostream & o, Fixed const & ref )
{
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

Fixed & Fixed::min(Fixed & a, Fixed & b )
{
	return (a < b ? a : b);
}

Fixed const & Fixed::min(Fixed const & a , Fixed const & b )
{
	return (a < b ? a : b);
}

Fixed & Fixed::max(Fixed & a , Fixed & b )
{
	return (a > b ? a : b);
}

Fixed const & Fixed::max(Fixed const & a, Fixed const & b )
{
	return (a > b ? a : b);
}

int const Fixed::_fbits = 8;
