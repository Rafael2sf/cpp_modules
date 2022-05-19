#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed
{
	public:
		Fixed( void );
		~Fixed();
		Fixed( Fixed const & );
		int	getRawBits( void ) const;
		void setRawBits( int const raw );

		Fixed & operator =( Fixed const & );

	private:
		int _value;
		static int const _bits;
};

#endif /* FIXED_HPP */
