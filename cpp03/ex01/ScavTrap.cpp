#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string &n): ClapTrap(n)
{
	setEnergyPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << BLUE << "ScavTrap constructor called for " << getName() << RESET << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << BLUE << "ScavTrap destructor called!" << RESET << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << BLUE << "ScavTrap " << getName() << " is now in Gate Keeper Mode!" << RESET << std::endl;
}