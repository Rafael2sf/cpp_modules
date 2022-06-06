#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class	Character: public ICharacter
{
	public:
		Character( void );
		~Character();
		Character( Character const & );
		Character & operator=( Character const & );

	private:
};

#endif /* CHARACTER_HPP */
