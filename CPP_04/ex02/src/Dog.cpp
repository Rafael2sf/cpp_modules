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
		this->_brain->setIdea(i, ref._brain->getIdea(i));
	return (*this);
}

void Dog::makeSound( void ) const
{
	std::cout << "** woof woof **" << std::endl;
}

bool	Dog::setIdea( int index, std::string idea )
{
	return (this->_brain->setIdea(index, idea));
}

std::string	Dog::getIdea( int index )
{
	return (this->_brain->getIdea(index));
}
