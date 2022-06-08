#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ): Form("Shrubbery", 150, 150), _target("")
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ): Form("Shrubbery", 150, 150), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & ref ): Form(ref), _target(ref._target)
{}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	( void )rhs;
	std::cerr << "Sorry, forms are unique!" << std::endl;
	return (*this);
}

void ShrubberyCreationForm::execute( Bureaucrat const & executor )
{
	( void )executor;
	srand(time(NULL));
	std::string	def_tree(" @@@@@\n@@@@@@@\n@@@@@@@\n @@@@@\n  | |\n  | |\n__/ \\__\n");
	std::string	buf, line;
	std::ifstream in;
	std::ofstream out;
	int	i = 0;
	int	index = std::rand() % 4;

	out.open(this->_target + "_shrubbery");
	if (!out.is_open())
	{
		// throw exception
		std::cerr << "Failed to output ascii tree to " << this->getName() << "_shrubbery" << std::endl;
		return ;
	}
	in.open("./src/tree.ascii");
	if (in.is_open())
	{
		while (true)
		{
			std::getline(in, line);
			while (line.length() == 0 && in.good())
				std::getline(in, line);
			buf = line + '\n';
			while (line.length() != 0 && in.good())
			{
				std::getline(in, line);
				buf.append(line + '\n');
			}
			if (i == index && buf.length() != 0)
			{
				out.write(buf.c_str(), buf.length());
				in.close();
				out.close();
				return ;
			}
			if (!in.good())
			{
				// throw exception
				in.close();
				break ;
			}
			buf.clear();
			i++;
		}
	}
	out.write(def_tree.c_str(), def_tree.length());
	out.close();
}
