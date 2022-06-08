#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Form;

class	Bureaucrat
{
	public:
		~Bureaucrat();
		Bureaucrat( std::string name, int grade );
		Bureaucrat( Bureaucrat const & ref );
		Bureaucrat & operator=( Bureaucrat const & rhs );
		std::string const getName( void ) const;
		int getGrade( void ) const;
		void incrGrade( void );
		void decrGrade( void );
		bool signForm( Form & );
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

	protected:
		Bureaucrat( void );
		std::string const _name;
		int _grade;
};

std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs );

#endif /* BUREAUCRAT_HPP */
