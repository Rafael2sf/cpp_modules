#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ): _name(""), _grade(150)
{}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat::Bureaucrat( std::string name, int grade ): _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat( Bureaucrat const & ref ): _name(ref._name)
{
	*this = ref;
}

Bureaucrat & Bureaucrat::operator=( Bureaucrat const & rhs )
{
	this->_grade = rhs._grade;
	return (*this);
}

std::string const Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void Bureaucrat::incrGrade( void )
{
	if ((this->_grade - 1) < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade -= 1;
	std::cout << this->_name << " has been promoted to ";
	std::cout << this->_grade << " grade" << std::endl;
}

void Bureaucrat::decrGrade( void )
{
	if ((this->_grade + 1) > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += 1;
	std::cout << this->_name << " has been demoted to ";
	std::cout << this->_grade << " grade" << std::endl;
}

std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs )
{
	o << rhs.getName() << ", bureaucrat grade ";
	o << rhs.getGrade() << std::endl;
	return (o);
}

const char *Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	std::cout << "bureaucrat grade too high" << std::endl;
	return ("invalid grade");
}

const char *Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	std::cout << "bureaucrat grade too low" << std::endl;
	return ("invalid grade");
}
