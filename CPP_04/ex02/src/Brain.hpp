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
		bool		setIdea( int index, std::string idea );
		std::string	getIdea( int index );
	protected:
		std::string _ideas[100];
};

#endif /* BRAIN_HPP */
