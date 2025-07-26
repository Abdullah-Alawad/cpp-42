#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie *newZombie = new Zombie(name);
	if (!newZombie)
		std::cout << "Memory Allocation Failed..." << std::endl;
	return newZombie;
}