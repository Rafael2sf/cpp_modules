#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main( void )
{
	{
		try { Form	form1("1", 0, 42); } catch ( const Form::GradeTooHighException & e )
		{ e.what(); }
		try { Form	form2("2", 42, 151); } catch ( const Form::GradeTooLowException & e )
		{ e.what(); }
	}
	std::cout << std::endl;
	{
		Bureaucrat	person("The guy", 42);
		Form		form("internship", 41, 69);

		std::cout << person;
		std::cout << form;
		person.signForm(form);
		person.incrGrade();
		person.signForm(form);
		person.signForm(form);
		std::cout << form;
	}
	std::cout << std::endl;
	{
		Bureaucrat	person("The guy", 42);
		Form		form("internship", 41, 69);
		try { form.beSigned(person); } catch ( const std::exception & e )
		{ e.what(); }
		person.incrGrade();
		form.beSigned(person);
		form.beSigned(person);
	}
	return (0);
}
