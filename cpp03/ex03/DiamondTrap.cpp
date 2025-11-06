#include "DiamondTrap.hpp"
		
DiamondTrap::DiamondTrap(): ClapTrap()
{
    name = "deault diamond name";
    std::cout << MAGENTA << "DiamondTrap constructor called for " << name << RESET << std::endl;
}
		
DiamondTrap::DiamondTrap(std::string &n): ClapTrap(n), ScavTrap(n), FragTrap(n)
{
    std::string clapName = n + "_clap_name";
    name = n;
    setName(clapName);
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << MAGENTA << "DiamondTrap " << name << " constructed!" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy): name(copy.name)
{
	setName(copy.getName());
	setAttackDamage(copy.getAttackDamage());
	setHitPoints(copy.getHitPoints());
	setEnergyPoints(copy.getEnergyPoints());
	std::cout << CYAN << "Diamond copy constructor called for " << getName() << RESET << std::endl;
}
DiamondTrap &DiamondTrap::operator=(DiamondTrap &copy)
{
    if (this != &copy)
    {
        name = copy.name;
        setName(copy.getName());
        setAttackDamage(copy.getAttackDamage());
        setHitPoints(copy.getHitPoints());
        setEnergyPoints(copy.getEnergyPoints());
    }
    return (*this);
}
		
DiamondTrap::~DiamondTrap()
{
    std::cout << MAGENTA << "DiamondTrap " << name << " destroyed!" << RESET << std::endl;
}
		
void DiamondTrap::whoAmI()
{
    std::cout << "I am DiamondTrap " << this->name
              << ", and my ClapTrap name is " << getName()
              << std::endl;
}