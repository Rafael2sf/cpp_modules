#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class	Form
{
	public:
		~Form();
		Form( Form const & );
		Form( std::string name, int sign_grade, int execute_grade );
		Form & operator=( Form const & );
		std::string const getName( void ) const;
		bool isSigned( void ) const;
		int  getSignGrade( void ) const;
		int  getExecuteGrade( void ) const;
		bool beSigned( Bureaucrat const & );
		class	GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class	GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		Form( void );
		std::string const _name;
		bool _is_signed;
		int const _sign_grade;
		int const _execute_grade;
};

std::ostream & operator<<( std::ostream & o, Form const & rhs );

#endif /* FORM_HPP */
