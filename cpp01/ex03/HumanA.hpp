#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon &wa;

	public:
		void attack();
		HumanA(const std::string &n, Weapon &w);
};

#endif