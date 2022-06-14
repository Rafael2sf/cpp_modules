#include "main.hpp"

static int	get_type( std::string & _str );

int	main( int argc, char **argv )
{
	if (argc != 2 || !argv[1][0])
	{
		std::cout << "Usage: ./prog <param>" << std::endl;
		return (1);
	}
	std::string	input = std::string(argv[1]);
	std::cout << std::fixed << std::setprecision(1);
	switch (get_type(input))
	{
		case TYPE_CHR:
			char_cast(input);
			break ;
		case TYPE_INT:
			int_cast(input);
			break ;
		case TYPE_FLT:
			float_cast(input);
			break ;
		case TYPE_DBL:
			double_cast(input);
			break ;
		default:
			std::cout << "Invalid paremeter" << std::endl;
			return (1);
	}
	return (0);
}

static int	get_type( std::string  & _str )
{
	bool	has_dot = false, has_f = false;
	int		i = 0;

	if (_str == "nan" || _str == "+inf" || _str == "-inf")
		return (TYPE_DBL);
	else if (_str == "nanf" || _str == "+inff" || _str == "-inff")
		return (TYPE_FLT);

	if (_str.length() == 1 && !isdigit(_str[0]))
		return (TYPE_CHR);
	if (_str[0] == '-' || _str[0]== '+')
		i++;
	if (!isdigit(_str[i]))
		return (TYPE_UNK);
	while (_str[i] == '0')
		_str.erase(i, 1);

	while (_str[i])
	{
		 if (_str[i] == '.' && !has_dot && isdigit(_str[i + 1]))
			has_dot = true;
		else if (_str[i] == 'f' && !_str[i + 1])
			has_f = true;
		else if (!isdigit(_str[i]))
			break ;
		i++;
	}

	if (!_str[i])
	{
		if (!has_dot && !has_f)
			return (TYPE_INT);
		else if (!has_f && has_dot)
			return (TYPE_DBL);
		else if (has_f && has_dot)
			return (TYPE_FLT);
	}
	return (TYPE_UNK);
}
