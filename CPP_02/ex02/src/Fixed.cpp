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
	std::cout << "(=) operator called" << std::endl;
	(this->_val) = ref.getRawBits();
	return (*this);
}

Fixed Fixed::operator+( Fixed const & ref ) const
{
	std::cout << "(+) operator called" << std::endl;
	Fixed ret = Fixed();
	ret.setRawBits(this->_val + ref.getRawBits());
	return (ret);
}

Fixed Fixed::operator-( Fixed const & ref ) const
{
	std::cout << "(-) operator called" << std::endl;
	Fixed ret = Fixed();
	ret.setRawBits(this->_val - ref.getRawBits());
	return (ret);
}

Fixed Fixed::operator*( Fixed const & ref ) const
{
	std::cout << "(*) operator called" << std::endl;
	Fixed ret = Fixed();
	ret.setRawBits(((long long)this->_val * (long long)ref.getRawBits()) >> this->_fbits);
	return (ret);
}

Fixed Fixed::operator/( Fixed const & ref ) const
{
	std::cout << "(/) operator called" << std::endl;
	Fixed ret = Fixed();
	ret.setRawBits(((long long)this->_val << this->_fbits) / ref.getRawBits());
	return (ret);
}

Fixed & Fixed::operator++( void )
{
	std::cout << "(++ ) operator called" << std::endl;
	(this->_val++);
	return (*this);
}

Fixed	Fixed::operator++( int dummy )
{
	std::cout << "( ++) operator called" << std::endl;
	( void )dummy;
	Fixed	tmp = Fixed(*this);
	(this->_val++);
	return (tmp);
}

Fixed & Fixed::operator--( void )
{
	std::cout << "(-- ) operator called" << std::endl;
	(this->_val--);
	return (*this);
}

Fixed	Fixed::operator--( int dummy )
{
	std::cout << "( --) operator called" << std::endl;
	( void )dummy;
	Fixed	tmp = Fixed(*this);
	(this->_val--);
	return (tmp);
}

bool	Fixed::operator==( Fixed const & ref ) const
{
	std::cout << "(==) operator called" << std::endl;
	return (this->_val == ref.getRawBits());
}

bool	Fixed::operator!=( Fixed const & ref ) const
{
	std::cout << "(!=) operator called" << std::endl;
	return (this->_val != ref.getRawBits());
}

bool	Fixed::operator<( Fixed const & ref ) const
{
	std::cout << "(<) operator called" << std::endl;
	return (this->_val < ref.getRawBits());
}

bool	Fixed::operator>( Fixed const & ref ) const
{
	std::cout << "(>) operator called" << std::endl;
	return (this->_val > ref.getRawBits());
}

bool	Fixed::operator<=( Fixed const & ref ) const
{
	std::cout << "(<=) operator called" << std::endl;
	return (this->_val <= ref.getRawBits());
}

bool	Fixed::operator>=( Fixed const & ref ) const
{
	std::cout << "(>=) operator called" << std::endl;
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
