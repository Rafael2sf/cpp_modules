#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

static int	rcat(std::ifstream &i_fd, std::ofstream &o_fd,
		std::string fstr, std::string rstr)
{
	std::string	buf, tmp;
	size_t		index, fstr_len;

	while (!i_fd.eof())
	{
		std::getline(i_fd, tmp);
		buf.append(tmp + "\n");
	}
	fstr_len = fstr.size();
	while (!buf.empty())
	{
		index = buf.find(fstr);
		if (index == buf.npos)
		{
			o_fd << buf;
			break ;
		}
		if (index > 0)
			o_fd << buf.substr(0, index);
		buf.erase(0, index + fstr_len);
		o_fd << rstr;
	}
	i_fd.close();
	o_fd.close();
	return (0);
}

int main(int argc, char **argv)
{
	std::ifstream	i_fd;
	std::ofstream	o_fd;
	std::string		infile, rstr, fstr;

	if (argc != 4)
	{
		std::cerr << "Usage: <file> <s1> <s2>\n";
		return (1);
	}
	infile.assign(argv[1]);
	i_fd.open((infile).c_str());
	if (i_fd.is_open() == false)
	{
		std::perror("error");
		return (1);
	}
	o_fd.open((infile + ".replace").c_str());
	if (o_fd.is_open() == false)
	{
		i_fd.close();
		std::perror("error");
		return (1);
	}
	fstr.assign(argv[2]);
	rstr.assign(argv[3]);
	return (rcat(i_fd, o_fd, fstr, rstr));
}
