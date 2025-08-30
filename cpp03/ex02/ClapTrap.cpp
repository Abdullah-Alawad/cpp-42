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
	std::cout << "Constructor called for " << name << std::endl;
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
	std::cout << "ClapTrap " << YELLOW << name << RESET <<" destructor called!" << std::endl;
}
		
void ClapTrap::attack(const std::string &target)
{
	if (hitPoints <= 0)
	{
		std::cout << RED << "ClapTrap " << getName() << " is dead!" << RESET <<std::endl;
		return ;
	}
	if (energyPoints <= 0)
	{
		std::cout << RED << "ClapTrap " << getName() << " has no energy points!" << RESET <<std::endl;
		return ;
	}
	std::cout << RED << "ClapTrap " << getName() << " attacks " << target
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
		std::cout << GREEN << "ClapTrap " << getName() << " is dead :)" << RESET << std::endl;
		return ;
	}
	if (energyPoints <= 0)
	{
		std::cout << GREEN << "ClapTrap " << getName() << " has no energy points :(" << RESET << std::endl;
		return ;
	}
	energyPoints--;
	hitPoints += amount;
	std::cout << GREEN << "ClapTrap " << getName() << " repairs iself with "
		<< amount << " hit points!\nhealth: " << RESET << hitPoints << std::endl;
}

void ClapTrap::setName(std::string name)
{
	this->name = name;
}

std::string ClapTrap::getName()
{
	return name;
}

std::string ClapTrap::getName() const
{
	return name;
}
		
void ClapTrap::setHitPoints(int n)
{
	hitPoints = n;
}
		
void ClapTrap::setEnergyPoints(int n)
{
	energyPoints = n;
}
		
void ClapTrap::setAttackDamage(int n)
{
	attackDamage = n;
}
 /* ************************************************ */
int ClapTrap::getHitPoints()
{
	return hitPoints;
}

int ClapTrap::getEnergyPoints()
{
	return energyPoints;
}
		
int ClapTrap::getAttackDamage()
{
	return attackDamage;
}

int ClapTrap::getHitPoints() const
{
	return hitPoints;
}

int ClapTrap::getEnergyPoints() const
{
	return energyPoints;
}
		
int ClapTrap::getAttackDamage() const
{
	return attackDamage;
}
