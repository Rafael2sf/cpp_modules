#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <stdlib.h>
# include "Form.hpp"

class	RobotomyRequestForm: public Form
{
	public:
		~RobotomyRequestForm();
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( RobotomyRequestForm const & );
		RobotomyRequestForm & operator=( RobotomyRequestForm const & );
		void execute( Bureaucrat const & executor );
		class	RobotomyFailedException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		RobotomyRequestForm( void );
		std::string const _target;
};

#endif /* ROBOTOMYREQUESTFORM_HPP */
