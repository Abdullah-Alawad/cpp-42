#include <iostream>

int	main(int argc, char *argv[])
{
	int	i = 0;
	int j = 1;

	if (argc > 1)
	{
		while (j <  argc)
		{
			i = 0; 
			while (argv[j][i])
			{
				argv[j][i] = std::toupper(argv[j][i]);
				i++;
			}
			std::cout << argv[j];
			j++;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}