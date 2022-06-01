#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class	Animal
{
	public:
		Animal( void );
		virtual ~Animal();
		Animal( Animal const & );
		Animal & operator=( Animal const & );

		virtual void	makeSound( void ) const;
		std::string	getType( void ) const;
	protected:
		std::string	_type;
};

#endif /* ANIMAL_HPP */
