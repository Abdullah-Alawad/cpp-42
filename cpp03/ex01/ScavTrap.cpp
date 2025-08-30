#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << CYAN << "ScavTrap constructor called for " << getName() << RESET << std::endl;

}

ScavTrap::ScavTrap(std::string &n): ClapTrap(n)
{
	setEnergyPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << CYAN << "ScavTrap constructor called for " << getName() << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
	setName(copy.getName());
	setAttackDamage(copy.getAttackDamage());
	setHitPoints(copy.getHitPoints());
	setEnergyPoints(copy.getEnergyPoints());
	std::cout << CYAN << "ScavTrap copy constructor called for " << getName() << RESET << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << CYAN << "ScavTrap " << getName() << " destructor called!" << RESET << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{
	std::cout << CYAN << "ScavTrap copy constructor called for " << getName() << RESET << std::endl;
	if (this != &obj)
	{
		this->setName(obj.getName());
		this->setHitPoints(obj.getHitPoints());
		this->setEnergyPoints(obj.getEnergyPoints());
		this->setAttackDamage(obj.getAttackDamage());
	}
	return (*this);
}

void ScavTrap::guardGate()
{
	std::cout << CYAN << "ScavTrap " << getName() << " is now in Gate Keeper Mode!" << RESET << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (getHitPoints() <= 0)
	{
		std::cout << WHITE << "ScavTrap " << getName() << " is dead!" << RESET << std::endl;
		return ;
	}
	if (getEnergyPoints() <= 0)
	{
		std::cout << WHITE << "ScavTrap " << getName() << " has no energy points!" << RESET << std::endl;
		return ;
	}
	std::cout << WHITE << "ScavTrap " << " attacks " << target
		<< ", causing " << getAttackDamage() << " points of damage!" << RESET << std::endl;
	setEnergyPoints(getEnergyPoints() - 1);
}
