#include "Dog.hpp"

Dog::Dog( void )
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "It's a " << this->_type << std::endl;
}

Dog::~Dog()
{
	std::cout << "Good bye " << this->_type << std::endl;
	delete this->_brain;
}

Dog::Dog( Dog const & ref )
{
	this->_brain = new Brain();
	std::cout << ref._type << " cloned" << std::endl;
	*this = ref;
}

Dog & Dog::operator=( Dog const & ref )
{
	this->_type = ref._type;
	for (int i = 0; i < 100; i++)
		(this->_brain->_ideas)[i] = (ref._brain->_ideas)[i];
	return (*this);
}

void Dog::makeSound( void ) const
{
	std::cout << "** woof woof **" << std::endl;
}

std::string Dog::getType( void ) const
{
	return (this->_type);
}

bool	Dog::setIdea( std::string idea )
{
	int	i = 0;

	if (idea == "")
		return (false);
	while (i < 100)
	{
		if ((this->_brain->_ideas)[i] == "")
		{
			(this->_brain->_ideas)[i] = idea;
			return (true);
		}
		i++;
	}
	return (false);
}

std::string	Dog::getIdea( int index )
{
	if (index >= 0 && index < 100)
		return ((this->_brain->_ideas)[index]);
	return ("");
}
