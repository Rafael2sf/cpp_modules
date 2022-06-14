#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template< typename T >
class	Array
{
	public:
		Array< T >( void )
		{
			_data = new T[0];
			_n = 0;
		}
		~Array< T >()
		{
			delete[] _data;
		}
		Array & operator=( Array< T > const & rhs )
		{
			unsigned int	i = 0;

			this->_n = rhs._n;
			while (i < rhs._n)
			{
				(this->_data)[i] = (rhs._data)[i];
				i++;
			}
			return (*this);
		}
		T & operator[]( std::size_t idx )
		{
			if (idx < 0 || idx >= this->_n)
				throw std::out_of_range("index is out of range in array subscript");
			return ((this->_data)[idx]);
		}
		Array( Array< T > const & ref )
		{
			this->_data = new T[ref._n];
			*this = ref;
		}
		Array( unsigned int size )
		{
			this->_data = new T[size];
			this->_n = size;
		}
		unsigned int size( void ) const
		{
			return (this->_n);
		}

	private:
		T				*_data;
		unsigned int	_n;
};

#endif /* ARRAY_HPP */
