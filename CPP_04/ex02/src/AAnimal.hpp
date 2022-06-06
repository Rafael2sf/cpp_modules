#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class	AAnimal
{
	public:
		AAnimal( void );
		virtual ~AAnimal();
		AAnimal( AAnimal const & );
		AAnimal & operator=( AAnimal const & );

		virtual void	makeSound( void ) const = 0;
		std::string		getType( void ) const;
	protected:
		std::string	_type;
};

#endif /* AANIMAL_HPP */
