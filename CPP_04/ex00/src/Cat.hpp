#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class	Cat: public Animal
{
	public:
		Cat( void );
		~Cat();
		Cat( Cat const & );
		Cat & operator=( Cat const & );

		void	makeSound( void ) const;
		std::string getType( void ) const;
	private:
		std::string	_type;
};

#endif /* CAT_HPP */
