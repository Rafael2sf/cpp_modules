#include <iostream>

int	main(int argc, char **argv)
{
	int i	= 1;
	int	len = 0;

	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (i < argc)
	{
		len = strlen(argv[i]);
		for (int j = 0; j < len; j++)
			argv[i][j] = toupper(argv[i][j]);
		std::cout << argv[i++] << "";
	}
	std::cout << std::endl;
	return (0);
}
