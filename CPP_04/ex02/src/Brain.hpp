#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class	Brain
{
	public:
		Brain( void );
		~Brain();
		Brain( Brain const & );
		Brain & operator=( Brain const & );
		std::string _ideas[100];
};

#endif /* BRAIN_HPP */
