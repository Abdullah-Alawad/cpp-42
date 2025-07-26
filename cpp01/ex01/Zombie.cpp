#include "Zombie.hpp"

Zombie::Zombie()
{
	name = "default";
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << name << " is destroyed!!" << std::endl;
}

void Zombie::setName(std::string n)
{
	name = n;
}