#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class	Ice: public AMateria
{
	public:
		Ice( void );
		~Ice();
		Ice( Ice const & );
		Ice & operator=( Ice const & );
		AMateria *clone( void ) const;
		void use( ICharacter & target );
};

#endif /* ICE_HPP */
