#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int	main( void )
{
	Bureaucrat				me("me", 1);
	ShrubberyCreationForm	form("home");
	form.execute(me);
	return (0);
}
