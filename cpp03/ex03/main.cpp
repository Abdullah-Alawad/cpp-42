#include "FragTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
	std::string n = "Abdullah";
	std::string y = "Yoda";
	FragTrap a(n);
	FragTrap b(y);
	FragTrap c;
	c = a;

	 a.attack("Yoda");
	 b.highFivesGuys();
	 c.highFivesGuys();
	// b.takeDamage(4);
	// b.beRepaired(3);

	// a.attack("sith");
	// a.attack("obi-wan kenobi");
}