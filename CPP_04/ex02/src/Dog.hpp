#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include <string>
#include "AAnimal.hpp"
#include "Brain.hpp"

class	Dog: public AAnimal
{
	public:
		Dog( void );
		~Dog();
		Dog( Dog const & );
		Dog & operator=( Dog const & );

		void		makeSound( void ) const;
		bool		setIdea( int index, std::string idea );
		std::string	getIdea( int index );
	private:
		Brain *		_brain;
};

#endif /* DOG_HPP */
