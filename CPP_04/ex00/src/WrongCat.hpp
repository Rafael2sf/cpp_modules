#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class	WrongCat: public WrongAnimal
{
	public:
		WrongCat( void );
		~WrongCat();
		WrongCat( WrongCat const & );
		WrongCat & operator=( WrongCat const & );

		void		makeSound( void ) const;
};

#endif /* WRONGCAT_HPP */
