#include "ClapTrap.hpp"

int main()
{
	std::string n = "Abdullah";
	std::string y = "Yoda";
	ClapTrap a(n);
	ClapTrap b(y);

	a.attack("Yoda");
	b.takeDamage(4);
	b.beRepaired(3);

	a.attack("sith");
	a.attack("obi-wan kenobi");
}