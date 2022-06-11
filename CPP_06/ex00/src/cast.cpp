#include "main.hpp"

void	char_cast( const std::string & _s )
{
	char	c;

	c = _s[0];
	if (isprint(c))
		std::cout << "char: '" << c << '\'' << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void	int_cast( const std::string & _s )
{
	int			i;
	int			len = _s.length() - (_s[0] == '-' || _s[0] == '+');
	long		l = strtol(_s.c_str(), NULL, 10);

	if (len > 10 || l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min())
	{
		std::cout << "char: Impossible\nint: Impossible\nfloat: Impossible\ndouble: Impossible" << std::endl;
		return ;
	}
	i = atoi(_s.c_str());
	if (i > 127 || i < 0)
		std::cout << "char: Impossible" << std::endl;
	else if (isprint(static_cast<char>(i)))
		std::cout << "char: '" << static_cast<char>(i) << '\'' << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void	float_cast( const std::string & _s )
{
	float				f;
	double				d = strtod(_s.c_str(), NULL);

	std::cout << d << std::endl;
	(void)d;
	if (!isdigit(_s[1]))
	{
		std::string tmp = _s;
		tmp.erase(tmp.length() - 1, 1);
		std::cout << "char: Impossible\nint: Impossible\nfloat: " << _s << "\ndouble: " << tmp << std::endl;
		return ;
	}
	if (d > std::numeric_limits<float>::max() 
		|| d < (std::numeric_limits<float>::max() * -1))
	{
		std::cout << "char: Impossible\nint: Impossible\nfloat: Impossible\ndouble: Impossible" << std::endl;
		return ;
	}
	f = strtof(_s.c_str(), NULL);
	if (f > 127.0f || f < 0.0f)
		std::cout << "char: Impossible" << std::endl;
	else if (isprint(static_cast<char>(f)))
		std::cout << "char: '" << static_cast<char>(f) << '\'' << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if ((f > 0 && static_cast<int>(f) < 0)
		|| f > std::numeric_limits<int>::max() 
		|| f < std::numeric_limits<int>::min())
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << f << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void	double_cast( const std::string & _s )
{
	errno = 0;
	double	d = strtod(_s.c_str(), NULL);

	if (!isdigit(_s[1]))
	{
		std::cout << "char: Impossible\nint: Impossible\nfloat: " << _s << "f\ndouble: " << _s << std::endl;
		return ;
	}
	if (errno == ERANGE)
	{
		std::cout << "char: Impossible\nint: Impossible\nfloat: Impossible\ndouble: Impossible" << std::endl;
		return ;
	}
	if (d > 127.0 || d < 0.0)
		std::cout << "char: Impossible" << std::endl;
	else if (isprint(static_cast<char>(d)))
		std::cout << "char: '" << static_cast<char>(d) << '\'' << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (d > std::numeric_limits<int>::max() 
		|| d < std::numeric_limits<int>::min())
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	if (d > std::numeric_limits<float>::max() 
		|| d < (std::numeric_limits<float>::max() * -1))
		std::cout << "float: Impossible" << std::endl;
	else
	std::cout << "float: " << static_cast<float>(d) << std::endl;
	std::cout << "double: " << d << std::endl;
}
