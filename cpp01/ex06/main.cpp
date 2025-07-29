#include "Harl.hpp"

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cout << "must have one argument" << std::endl;
		return (1);
	}
	std::string comp(av[1]);
	Harl h;
	h.complain(comp);
}