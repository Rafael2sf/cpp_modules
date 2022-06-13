#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
	std::cout << "new materia source" << std::endl;
	for (int i = 0; i < 4; i++)
		(this->_inv)[i] = 0;
}

MateriaSource::~MateriaSource()
{
	std::cout << "deleted materia source" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if ((this->_inv)[i] != 0)
		{
			delete (this->_inv)[i];
			(this->_inv)[i] = 0;
		}
	}
}

MateriaSource::MateriaSource( MateriaSource const & ref )
{
	for (int i = 0; i < 4; i++)
		(this->_inv)[i] = 0;
	*this = ref;
}

MateriaSource & MateriaSource::operator=( MateriaSource const & rhs )
{
	for (int i = 0; i < 4; i++)
	{
		if (rhs._inv[i] != 0)
			(this->_inv)[i] = rhs._inv[i]->clone();
	}
	return (*this);
}

void MateriaSource::learnMateria( AMateria * ref )
{
	if (!ref)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if ((this->_inv)[i] == ref)
		{
			std::cout << "materia " << ref->getType() << "(" << ref << ") already learned" << std::endl;
			return ;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if ((this->_inv)[i] == 0)
		{
			(this->_inv)[i] = ref;
			std::cout << "learned " << ref->getType() << " materia" << std::endl;
			return ;
		}
	}
}

AMateria *MateriaSource::createMateria( std::string const & type )
{
	for (int i = 0; i < 4; i++)
	{
		if ((this->_inv)[i] != 0 && (this->_inv)[i]->getType() == type)
			return ((this->_inv)[i]->clone());
	}
	return (0);
}
