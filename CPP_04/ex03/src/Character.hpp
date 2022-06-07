#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class	Character: public ICharacter
{
	public:
		~Character();
		Character( std::string name );
		Character( Character const & );
		Character & operator=( Character const & );
		std::string const & getName( void ) const;
		void unequip( int idx );
		void use( int idx, ICharacter & target );
		void equip( AMateria *m );

	private:
		Character( void );
		AMateria	*_inv[4];
		std::string	_name;
};

#endif /* CHARACTER_HPP */
