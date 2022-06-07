#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class	Cure: public AMateria
{
	public:
		Cure( void );
		~Cure();
		Cure( Cure const & );
		Cure & operator=( Cure const & );
		AMateria *clone( void ) const;
		void use( ICharacter & target );

};

#endif /* CURE_HPP */
