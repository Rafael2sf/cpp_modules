#ifndef FIXED_HPP
# define FIXED_HPP

#include <cmath>
#include <iostream>

class	Fixed
{
	public:
		Fixed( void );
		~Fixed();
		Fixed( int const & );
		Fixed( float const & );
		Fixed( Fixed const & );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

		Fixed & operator=( Fixed const & );
		Fixed	operator+( Fixed const & );
		Fixed	operator-( Fixed const & );

	private:
		int _val;
		static int const _fbits;
};

std::ostream & operator<<( std::ostream & o, Fixed const & );

#endif /* FIXED_HPP */
