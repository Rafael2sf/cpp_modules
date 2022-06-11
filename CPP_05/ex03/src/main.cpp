#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main( void )
{
	Bureaucrat	bureau("SomeBureaucrat", 42);
	Intern		intern;
	Form		*form;

	try 
	{
		form = intern.makeForm("test", "someone");
		bureau.signForm(*form);
		bureau.executeForm(*form);
		std::cout << *form;
		delete form;
	}
	catch ( const Intern::UnknownFormException & e )
	{
		e.what();
	}
	catch ( const std::exception & e )
	{
		e.what();
		delete form;
	}
	return (0);
}
