#include "Data.hpp"

Data::Data( void ): _x(0)
{}

Data::~Data()
{}

Data::Data( Data const & ref )
{
	*this = ref;
}

Data::Data( unsigned int n ): _x(n)
{}

Data & Data::operator=( Data const & rhs )
{
	this->_x = rhs._x;
	return (*this);
}

unsigned int	Data::getX( void ) const
{
	return (this->_x);
}

void	Data::setX( unsigned int val )
{
	this->_x = val;
}

uintptr_t	serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* 		deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
