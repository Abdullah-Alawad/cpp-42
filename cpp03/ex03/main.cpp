// #include "FragTrap.hpp"
// #include "ClapTrap.hpp"

#include "DiamondTrap.hpp"

int main()
{
	std::string n = "Abdullah";
	std::string y = "Yoda";
	DiamondTrap a(n);
	DiamondTrap b(y);
	DiamondTrap c(a);
	//c = a;

	 a.attack("Yoda");
	 c.whoAmI();
	 //b.highFivesGuys();
	 //c.highFivesGuys();
	// b.takeDamage(4);
	// b.beRepaired(3);

	// a.attack("sith");
	// a.attack("obi-wan kenobi");
}