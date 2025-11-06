#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string name;
	public:
		DiamondTrap();
		DiamondTrap(std::string &n);
		DiamondTrap(const DiamondTrap &copy);
		DiamondTrap &operator=(DiamondTrap &copy);
		~DiamondTrap();
		void whoAmI();
		std::string get_dname();
};

#endif