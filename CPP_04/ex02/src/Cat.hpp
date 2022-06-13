#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include <string>
#include "AAnimal.hpp"
#include "Brain.hpp"

class	Cat: public AAnimal
{
	public:
		Cat( void );
		~Cat();
		Cat( Cat const & );
		Cat & operator=( Cat const & );

		void		makeSound( void ) const;
		bool		setIdea( int index, std::string idea );
		std::string	getIdea( int index );
	private:
		Brain *		_brain;
};

#endif /* CAT_HPP */
