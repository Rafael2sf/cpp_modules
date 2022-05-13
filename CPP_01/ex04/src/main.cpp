#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	int			rsize;
	std::string	buf;
	std::size_t	found;

	if (argc != 4)
	{
		std::cerr << "Usage: <file> <s1> <s2>\n";
		return (1);
	}
	std::ifstream	fd(argv[1]);
	if (fd.is_open() == false)
	{
		std::perror("error");
		return (1);
	}
	rsize = strlen(argv[2]);
	while (1)
	{
		fd >> buf;
		if (fd.eof())
			break ;
		found = buf.find(argv[2]);
		if (found != buf.npos)
			std::cout << buf << "\n";
	}
	fd.close();
	return (0);
}
