#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class	Dog: public Animal
{
	public:
		Dog( void );
		~Dog();
		Dog( Dog const & );
		Dog & operator=( Dog const & );

		void	makeSound( void ) const;
		std::string getType( void ) const;
	private:
		std::string	_type;
};

#endif /* DOG_HPP */
