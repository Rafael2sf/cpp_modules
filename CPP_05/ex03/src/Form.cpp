#include "Form.hpp"

Form::Form( void )
: _name(""), _sign_grade(150), _execute_grade(150)
{
	if (this->_sign_grade < 1 || this->_execute_grade < 1)
		throw Form::GradeTooHighException();
	if (this->_sign_grade > 150 || this->_execute_grade > 150)
		throw Form::GradeTooLowException();
	this->_is_signed = false;
}

Form::~Form()
{}

Form::Form( std::string name, int sign_grade, int execute_grade )
: _name(name), _sign_grade(sign_grade), _execute_grade(execute_grade)
{
	if (this->_sign_grade < 1 || this->_execute_grade < 1)
		throw Form::GradeTooHighException();
	if (this->_sign_grade > 150 || this->_execute_grade > 150)
		throw Form::GradeTooLowException();
	this->_is_signed = false;
}

Form::Form( Form const & ref )
: _name(ref._name), _sign_grade(ref._sign_grade), _execute_grade(ref._execute_grade)
{
	if (this->_sign_grade < 1 || this->_execute_grade < 1)
		throw Form::GradeTooHighException();
	if (this->_sign_grade > 150 || this->_execute_grade > 150)
		throw Form::GradeTooLowException();
	this->_is_signed = false;
}

Form & Form::operator=( Form const & rhs )
{
	( void )rhs;
	std::cerr << "Sorry, forms can't be changed!" << std::endl;
	return (*this);
}

std::string const Form::getName( void ) const
{
	return (this->_name);
}

bool Form::isSigned( void ) const
{
	return (this->_is_signed);
}

int  Form::getSignGrade( void ) const
{
	return (this->_sign_grade);
}

int  Form::getExecuteGrade( void ) const
{
	return (this->_execute_grade);
}

bool Form::beSigned( Bureaucrat const & ref )
{
	if (this->_is_signed == true)
	{
		std::cout << "bureaucrat <" << ref.getName() << "> couldn't sign <" << this->_name;
		std::cout << "> form because it is already signed" << std::endl;
		return (false);
	}
	if (ref.getGrade() <= this->_sign_grade)
	{
		this->_is_signed = true;
		std::cout << "bureaucrat <" << ref.getName() << "> signed form <";
		std::cout << this->_name << ">" << std::endl;
		return (true);
	}
	throw Form::GradeTooLowException();
}

void Form::execute( Bureaucrat const & executor )
{
	if (this->_is_signed == false)
		throw Form::ExecutingNotSignedException();
	if (executor.getGrade() > this->_execute_grade)
		throw Form::GradeTooLowException();
	std::cout << "bureaucrat <" << executor.getName() << "> executed form <" << this->getName() << ">" << std::endl;
}

std::ostream & operator<<( std::ostream & o, Form const & rhs )
{
	o << "form <" << rhs.getName() << "> signed: ";
	o << (rhs.isSigned() ? "✓" : "x");
	o << ", sign_grade: " << rhs.getSignGrade();
	o << ", execute_grade: " << rhs.getExecuteGrade() << std::endl;
	return (o);
}

const char *Form::GradeTooHighException::what( void ) const throw()
{
	std::cout << "form grade too high" << std::endl;
	return ("invalid grade");
}

const char *Form::GradeTooLowException::what( void ) const throw()
{
	std::cout << "form grade too low" << std::endl;
	return ("invalid grade");
}

const char *Form::ExecutingNotSignedException::what( void ) const throw()
{
	std::cout << "cannot execute a form that is not signed" << std::endl;
	return ("execution refused");
}
