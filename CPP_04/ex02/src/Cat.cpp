#include "Cat.hpp"

Cat::Cat( void )
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "It's a " << this->_type << std::endl;
}

Cat::~Cat()
{
	std::cout << "Good bye " << this->_type << std::endl;
	delete this->_brain;
}

Cat::Cat( Cat const & ref )
{
	this->_brain = new Brain();
	std::cout << ref._type << " cloned" << std::endl;
	*this = ref;
}

Cat & Cat::operator=( Cat const & ref )
{
	this->_type = ref._type;
	for (int i = 0; i < 100; i++)
		(this->_brain->_ideas)[i] = (ref._brain->_ideas)[i];
	return (*this);
}

void Cat::makeSound( void ) const
{
	std::cout << "** meow meow **" << std::endl;
}

std::string Cat::getType( void ) const
{
	return (this->_type);
}

bool	Cat::setIdea( std::string idea )
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

std::string	Cat::getIdea( int index )
{
	if (index >= 0 && index < 100)
		return ((this->_brain->_ideas)[index]);
	return ("");
}
