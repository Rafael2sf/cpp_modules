#include "Brain.hpp"

Brain::Brain( void )
{
	std::cout << "Animal brain constructed" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Animal brain deconstructed" << std::endl;
}

Brain::Brain( Brain const & ref )
{
	std::cout << "Animal brain cloned" << std::endl;
	*this = ref;
}

Brain & Brain::operator=( Brain const & rhs )
{
	std::cout << "Animal brain copied" << std::endl;
	int	i = 0;
	while (i < 100)
	{
		(this->_ideas)[i] = (rhs._ideas)[i];
		i++;
	}
	return (*this);
}
