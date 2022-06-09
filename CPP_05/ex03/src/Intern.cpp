#include "Intern.hpp"

Intern::Intern( void )
{}

Intern::~Intern()
{}

Intern::Intern( Intern const & ref )
{
	*this = ref;
}

Intern & Intern::operator=( Intern const & rhs )
{
	( void )rhs;
	std::cout << "I can't believe it! Interns are people too... you can't just copy them." << std::endl;
	return (*this);
}

Form *Intern::makeForm( std::string name, std::string target )
{
	std::string 	list[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++)
	{
		if (list[i] == name)
		{
			switch (i)
			{
				case 0:
					return (new ShrubberyCreationForm(target));
				case 1:
					return (new RobotomyRequestForm(target));
				case 2:
					return (new PresidentialPardonForm(target));
				default:
					break ;
			}
		}
	}
	throw Intern::UnknownFormException();
}

const char *Intern::UnknownFormException::what( void ) const throw()
{
	std::cout << "intern does not recognize this form" << std::endl;
	return ("intern invalid form");
}
