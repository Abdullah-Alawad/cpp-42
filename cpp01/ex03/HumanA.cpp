#include "HumanA.hpp"

void HumanA::attack()
{
	std::cout << name << " attacks with their " << wa.getType() << std::endl;
}

HumanA::HumanA(const std::string &n, Weapon &w): name(n), wa(w) {}