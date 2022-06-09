#include "ShrubberyCreationForm.hpp"

static std::string	getAsciiTree(std::ifstream & in, int index);

ShrubberyCreationForm::ShrubberyCreationForm( void ): Form("ShrubberyCreation", 145, 137), _target("")
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ): Form("ShrubberyCreation", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & ref ): Form(ref), _target(ref._target)
{}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	( void )rhs;
	std::cerr << "Sorry, forms can't be changed!" << std::endl;
	return (*this);
}

void ShrubberyCreationForm::execute( Bureaucrat const & executor )
{
	Form::execute(executor);
	std::string	def_tree(" @@@@@\n@@@@@@@\n@@@@@@@\n @@@@@\n  | |\n  | |\n__/ \\__\n");
	std::string tree;
	std::ifstream in;
	std::ofstream out;

	out.open((this->_target + std::string("_shrubbery")).c_str());
	if (!out.is_open())
		throw ShrubberyCreationForm::ShrubberyFailedException();
	in.open("./src/tree.ascii");
	if (in.is_open())
	{
		srand(time(NULL));
		tree = getAsciiTree(in, std::rand() % 4);
		in.close();
	}
	if (tree.length() > 0)
		out.write(tree.c_str(), tree.length());
	else
		out.write(def_tree.c_str(), def_tree.length());
	out.close();
}

static std::string	getAsciiTree(std::ifstream & in, int index)
{
	std::string	buf, line;
	int			i = 0;

	while (true)
	{
		std::getline(in, line);
		while (line.length() == 0 && in.good())
			std::getline(in, line);
		if (line.length() > 0)
			buf = line + '\n';
		while (line.length() != 0 && in.good())
		{
			std::getline(in, line);
			buf.append(line + '\n');
		}
		if (i == index && buf.length() != 0)
			return (buf);
		if (!in.good())
			return ("");
		buf.clear();
		i++;
	}
}

const char *ShrubberyCreationForm::ShrubberyFailedException::what( void ) const throw()
{
	std::cout << "failed to output ascii tree" << std::endl;
	return ("file error");
}
