#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	name = "default";
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(std::string &name)
{
	std::cout << "Constructor called" << std::endl;
	this->name = name;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
}
		
ClapTrap::ClapTrap(const ClapTrap &copy): name(copy.name), hitPoints(copy.hitPoints)
			, energyPoints(copy.energyPoints), attackDamage(copy.attackDamage) {}
		
ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
	if (this != &obj)
	{
		this->name = obj.name;
		this->hitPoints = obj.hitPoints;
		this->energyPoints = obj.energyPoints;
		this->attackDamage = obj.attackDamage;
	}
	return (*this);
}
		
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called!" << std::endl;
}
		
void ClapTrap::attack(const std::string &target)
{
	if (hitPoints <= 0)
	{
		std::cout << RED << "ClapTrap " << name << " is dead!" << RESET <<std::endl;
		return ;
	}
	if (energyPoints <= 0)
	{
		std::cout << RED << "ClapTrap " << name << " has no energy points!" << RESET <<std::endl;
		return ;
	}
	std::cout << RED << "ClapTrap " << " attacks " << target
		<< ", causing " << attackDamage << " points of damage!" << RESET << std::endl;
	energyPoints--;
}
		
void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints <= 0)
		std::cout << YELLOW << "ClapTrap " << name << " is already dead!" << RESET << std::endl;
	hitPoints -= amount;
	if (hitPoints < 0)
		hitPoints = 0;
	std::cout << YELLOW << "ClapTrap " << name << " took " << amount
		<< " points of damage!\nhealth: " << RESET << hitPoints << std::endl; 	
}
		
void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints <= 0)
	{
		std::cout << GREEN << "ClapTrap " << name << " is dead :)" << RESET << std::endl;
		return ;
	}
	if (energyPoints <= 0)
	{
		std::cout << GREEN << "ClapTrap " << name << " has no energy points :(" << RESET << std::endl;
		return ;
	}
	energyPoints--;
	hitPoints += amount;
	std::cout << GREEN << "ClapTrap " << name << " repairs iself with "
		<< amount << " hit points!\nhealth: " << RESET << hitPoints << std::endl;
}
