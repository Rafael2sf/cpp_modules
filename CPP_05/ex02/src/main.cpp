#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main( void )
{
	Bureaucrat				me("me", 26);
	Bureaucrat				also_me("alsome", 6);
	ShrubberyCreationForm	form("home");

	std::cout << me;
	std::cout << form;
	try { me.executeForm(form); } catch( const std::exception& e )
	{ e.what(); }
	try { me.signForm(form); } catch( const std::exception& e )
	{ e.what(); }
	me.incrGrade();
	try { form.beSigned(me); } catch( const std::exception& e )
	{ e.what(); }
	std::cout << also_me;
	try { form.execute(also_me); } catch( const std::exception& e )
	{ e.what(); }
	also_me.incrGrade();
	try { also_me.executeForm(form); } catch( const std::exception& e )
	{ e.what(); }
	std::cout << form;
	return (0);
}
