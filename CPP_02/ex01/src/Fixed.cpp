#include "Fixed.hpp"

Fixed::Fixed( void ): _val(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( int const & ref )
{
	std::cout << "Int constructor called" << std::endl;
	(this->_val) = (ref << this->_fbits);
}

Fixed::Fixed( float const & ref )
{
	std::cout << "Float constructor called" << std::endl;
	(this->_val) = roundf(ref * (float)(1 << this->_fbits));
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

int const Fixed::_fbits = 8;
