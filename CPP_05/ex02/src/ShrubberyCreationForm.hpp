#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
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

	private:
		ShrubberyCreationForm( void );
		std::string const _target;
};

#endif /* SHRUBBERYCREATIONFORM_HPP */
