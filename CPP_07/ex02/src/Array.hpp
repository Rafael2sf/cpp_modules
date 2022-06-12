#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template< typename T >
class	Array
{
	public:
		Array( void );
		~Array();
		Array( T const & );
		Array( unsigned int );
		Array & operator=( Array< T > const & );
		size_t size( void ) const;

	private:
		T		*_data;
		size_t	_n;
};

#endif /* ARRAY_HPP */
