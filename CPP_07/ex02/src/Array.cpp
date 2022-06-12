#include "Array.hpp"

template class Array<int>;

template< typename T >
Array< T >::Array( void )
{
	_data = new T[0];
	_n = 0;
}

template< typename T >
Array< T >::~Array()
{
	delete[] _data;
}

template< typename T >
Array< T >::Array( T const & ref )
{
	*this = ref;
}

template< typename T >
Array< T >::Array( unsigned int size )
{
	this->_data = new T[size];
	this->_n = size;
}

template< typename T >
Array< T > & Array< T >::operator=( Array< T > const & rhs )
{
	size_t	len = rhs._n;
	size_t	i = 0;

	this->_n = len;
	this->_data = new T[len];
	while (i < len)
	{
		(this->_data)[i] = (rhs._data)[i];
		i++;
	}
	return (*this);
}

template< typename T >
size_t	Array< T >::size( void ) const
{
	return (this->_n);
}
