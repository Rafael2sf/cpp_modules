#include "Character.hpp"

Character::Character( void )
{
	this->_name = "";
	for (int i = 0; i < 4; i++)
		(this->_inv[i]) = 0;
	std::cout << this->_name << " character is born" << std::endl;
}

Character::~Character()
{
	std::cout << this->_name << " character is dead" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if ((this->_inv)[i] != 0)
		{
			delete (this->_inv)[i];
			(this->_inv)[i] = 0;
		}
	}
}

Character::Character( Character const & ref )
{
	for (int i = 0; i < 4; i++)
		(this->_inv[i]) = 0;
	*this = ref;
}

Character & Character::operator=( Character const & rhs )
{
	std::cout << rhs._name << " character cloned" << std::endl;
	this->_name = rhs._name;
	for (int i = 0; i < 4; i++)
	{
		if ((this->_inv)[i] != 0)
		{
			delete (this->_inv)[i];
			(this->_inv)[i] = 0;
		}
		if (rhs._inv[i] != 0)
			(this->_inv)[i] = (rhs._inv[i])->clone();
	}
	return (*this);
}

Character::Character( std::string name ): _name(name)
{
	for (int i = 0; i < 4; i++)
		(this->_inv)[i] = 0;
	std::cout << this->_name << " character is born" << std::endl;
}

std::string const &	Character::getName( void ) const
{
	return (this->_name);
}

void	Character::unequip( int idx )
{
	if (idx < 0 || idx > 3 || (this->_inv)[idx] == 0)
		return ;
	std::cout << this->_name << " unequipped " << (this->_inv)[idx]->getType() << " materia" << std::endl;
	(this->_inv)[idx] = 0;
}

void	Character::use( int idx, ICharacter & target )
{
	if (idx < 0 || idx > 3 || (this->_inv)[idx] == 0)
		return ;
	(this->_inv)[idx]->use(target);
}

void	Character::equip( AMateria *m )
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if ((this->_inv)[i] == m)
		{
			std::cout << this->_name << " already has " << m->getType() << " materia (" << m << ") equipped" << std::endl;
			return ;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if ((this->_inv)[i] == 0)
		{
			(this->_inv)[i] = m;
			std::cout << this->_name << " equipped " << (this->_inv)[i]->getType() << " materia" << std::endl;
			return ;
		}
	}
}
