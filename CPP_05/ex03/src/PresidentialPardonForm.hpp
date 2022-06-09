#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
# include <stdlib.h>

class	PresidentialPardonForm: public Form
{
	public:
		~PresidentialPardonForm();
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( PresidentialPardonForm const & );
		PresidentialPardonForm & operator=( PresidentialPardonForm const & );
		void execute( Bureaucrat const & executor );

	private:
		PresidentialPardonForm( void );
		std::string const _target;
};

#endif /* PRESIDENTIALPARDONFORM_HPP */
