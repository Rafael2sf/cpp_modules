#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <stdlib.h>
# include <fstream>
# include "Form.hpp"

class	ShrubberyCreationForm: public Form
{
	public:
		~ShrubberyCreationForm();
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( ShrubberyCreationForm const & );
		ShrubberyCreationForm & operator=( ShrubberyCreationForm const & );
		void execute( Bureaucrat const & executor );
		class	ShrubberyFailedException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		ShrubberyCreationForm( void );
		std::string const _target;
};

#endif /* SHRUBBERYCREATIONFORM_HPP */
