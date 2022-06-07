#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class	MateriaSource: public IMateriaSource
{
	public:
		MateriaSource( void );
		~MateriaSource();
		MateriaSource( MateriaSource const & );
		MateriaSource & operator=( MateriaSource const & );
		void learnMateria( AMateria * );
		AMateria *createMateria( std::string const & type);

	private:
		AMateria	*_inv[4];
};

#endif /* MATERIASOURCE_HPP */
