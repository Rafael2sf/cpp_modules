#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ): Form("PresidentialPardon", 25, 5), _target("")
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm::PresidentialPardonForm( std::string target ): Form("PresidentialPardon", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & ref ): Form(ref), _target(ref._target)
{}

PresidentialPardonForm & PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	( void )rhs;
	std::cerr << "Sorry, forms can't be changed!" << std::endl;
	return (*this);
}

void PresidentialPardonForm::execute( Bureaucrat const & executor )
{
	Form::execute(executor);
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
