#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
#include <stdint.h>

class	Data
{
	public:
		Data( void );
		~Data();
		Data( unsigned int );
		Data( Data const & );
		Data & operator=( Data const & );
		
		unsigned int	getX( void ) const;
		void			setX( unsigned int );
	private:
		unsigned int	_x;
};

uintptr_t	serialize(Data* ptr);
Data* 		deserialize(uintptr_t raw);

#endif /* DATA_HPP */
