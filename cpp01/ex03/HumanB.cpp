#include "HumanB.hpp"

void HumanB::attack()
{
	std::cout << name << " attacks with their " << wb->getType() << std::endl;
}

HumanB::HumanB(const std::string &n)
{
	name = n;
}

void HumanB::setWeapon(Weapon &w)
{
	wb = &w;
}