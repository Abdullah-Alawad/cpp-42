#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
	std::string n = "Abdullah";
	std::string y = "Yoda";
	ScavTrap a(n);
	ScavTrap b(y);
	ScavTrap c;
	c = a;

	 a.attack("Yoda");
	 b.guardGate();
	 c.guardGate();
	 std::cout << a.getAttackDamage() << "  " << a.getEnergyPoints() <<  "  " << a.getHitPoints() << std::endl;
	// b.takeDamage(4);
	// b.beRepaired(3);

	// a.attack("sith");
	// a.attack("obi-wan kenobi");
}