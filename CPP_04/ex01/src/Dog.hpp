#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class	Dog: public Animal
{
	public:
		Dog( void );
		~Dog();
		Dog( Dog const & );
		Dog & operator=( Dog const & );

		void		makeSound( void ) const;
		std::string	getType( void ) const;
		bool		setIdea( std::string idea );
		std::string	getIdea( int index );
	private:
		std::string	_type;
		Brain *		_brain;
};

#endif /* DOG_HPP */
