#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ): Form("RobotomyRequest", 72, 45), _target("")
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm( std::string target ): Form("RobotomyRequest", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & ref ): Form(ref), _target(ref._target)
{}

RobotomyRequestForm & RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	( void )rhs;
	std::cerr << "Sorry, forms can't be changed!" << std::endl;
	return (*this);
}

void RobotomyRequestForm::execute( Bureaucrat const & executor )
{
	Form::execute(executor);
	srand(time(NULL));
	if ((rand() % 2))
		std::cout << this->_target << " has been robotomized" << std::endl;
	else
		throw RobotomyRequestForm::RobotomyFailedException();
}

const char *RobotomyRequestForm::RobotomyFailedException::what( void ) const throw()
{
	std::cout << "automated form failed it's execution" << std::endl;
	return ("bad luck");
}
