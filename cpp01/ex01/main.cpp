#include "Zombie.hpp"

int main()
{
	Zombie *zzz = zombieHorde(5, "mark");
	if (zzz)
	{
		for (int i = 0; i < 5; i++)
			zzz[i].announce();
		delete[] zzz;
	}
}