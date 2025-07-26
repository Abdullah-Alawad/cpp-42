#include "Zombie.hpp"

int main()
{
	Zombie *zzz = newZombie("Mark");
	zzz->announce();
	delete zzz;

	randomChump("pedro");
}