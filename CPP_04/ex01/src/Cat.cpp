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
		this->_brain->setIdea(i, ref._brain->getIdea(i));
	return (*this);
}

void Cat::makeSound( void ) const
{
	std::cout << "** meow meow **" << std::endl;
}

bool	Cat::setIdea( int index, std::string idea )
{
	return (this->_brain->setIdea(index, idea));
}

std::string	Cat::getIdea( int index )
{
	return (this->_brain->getIdea(index));
}
