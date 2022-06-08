#include "Bureaucrat.hpp"

int	main( void )
{
	Bureaucrat	person("The Great Bureaucrat", 42);
	person.decrGrade();
	std::cout << person;
	person.incrGrade();
	std::cout << person;
	person.incrGrade();
	std::cout << person;

	try
	{ Bureaucrat	person_a("a", 0); } catch ( Bureaucrat::GradeTooHighException & e )
	{ e.what(); }
	try
	{ Bureaucrat	person_b("b", 151); } catch ( Bureaucrat::GradeTooLowException & e )
	{ e.what(); }

	try
	{ Bureaucrat	person_c("c", 1); person_c.incrGrade();} catch ( Bureaucrat::GradeTooHighException & e )
	{ e.what(); }
	try
	{ Bureaucrat	person_d("d", 150); person_d.decrGrade(); } catch ( Bureaucrat::GradeTooLowException & e )
	{ e.what(); }

	return (0);
}
