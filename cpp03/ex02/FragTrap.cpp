#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << MAGENTA << "FragTrap constructor called for " << getName() << RESET << std::endl;
}
		
FragTrap::FragTrap(std::string &n): ClapTrap(n)
{
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << MAGENTA << "FragTrap constructor called for " << getName() << RESET << std::endl;
}
		
FragTrap &FragTrap::operator=(FragTrap &obj)
{
	std::cout << MAGENTA << "FragTrap copy constructor called for " << getName() << RESET << std::endl;
	if (this != &obj)
	{
		this->setName(obj.getName());
		this->setHitPoints(obj.getHitPoints());
		this->setEnergyPoints(obj.getEnergyPoints());
		this->setAttackDamage(obj.getAttackDamage());
	}
	return (*this);
}
		
FragTrap::~FragTrap()
{
	std::cout << MAGENTA << "FragTrap " << getName() << " destructor called!" << RESET << std::endl;
}
		
void FragTrap::highFivesGuys(void)
{
	std::cout << MAGENTA << "FragTrap " << getName() << " requests a high five!" << RESET << std::endl;
}