#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include <sstream>
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class	Intern
{
	public:
		Intern( void );
		~Intern();
		Intern( Intern const & );
		Intern & operator=( Intern const & );
		Form *makeForm( std::string name, std::string target );
		class	UnknownFormException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
};

#endif /* INTERN_HPP */
