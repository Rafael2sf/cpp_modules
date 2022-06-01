#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class	WrongAnimal
{
	public:
		WrongAnimal( void );
		~WrongAnimal();
		WrongAnimal( WrongAnimal const & );
		WrongAnimal & operator=( WrongAnimal const & );

		void	makeSound( void ) const;
		std::string	getType( void ) const;
	protected:
		std::string	_type;
};

#endif /* ANIMAL_HPP */
