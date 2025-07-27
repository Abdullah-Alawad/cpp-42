#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon *wb;

	public:
		void attack();
		HumanB(const std::string &n);
		void setWeapon(Weapon &w);
};

#endif