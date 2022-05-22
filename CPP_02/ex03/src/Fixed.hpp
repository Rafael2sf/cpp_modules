#ifndef FIXED_HPP
# define FIXED_HPP

#include <cmath>
#include <iostream>

class	Fixed
{
	public:
		// Constructors
		Fixed( void );
		~Fixed();
		Fixed( int const & );
		Fixed( float const & );
		Fixed( Fixed const & );

		// Member functions
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

		// Class functions
		static Fixed & min(Fixed &, Fixed & );
		static Fixed const & min(Fixed const &, Fixed const & );
		static Fixed & max(Fixed &, Fixed & );
		static Fixed const & max(Fixed const &, Fixed const & );

		// Arithmethic operators
		Fixed & operator=( Fixed const & );
		Fixed	operator+( Fixed const & ) const;
		Fixed	operator-( Fixed const & ) const;
		Fixed	operator*( Fixed const & ) const;
		Fixed	operator/( Fixed const & ) const;
		Fixed & operator++( void );
		Fixed	operator++( int );
		Fixed & operator--( void );
		Fixed	operator--( int );

		// Equality operators
		bool	operator==( Fixed const & ) const;
		bool	operator!=( Fixed const & ) const;
		bool	operator<( Fixed const & ) const;
		bool	operator>( Fixed const & ) const;
		bool	operator<=( Fixed const & ) const;
		bool	operator>=( Fixed const & ) const;

	private:
		int _val;
		static int const _fbits;
};

std::ostream & operator<<( std::ostream & o, Fixed const & );

#endif /* FIXED_HPP */
