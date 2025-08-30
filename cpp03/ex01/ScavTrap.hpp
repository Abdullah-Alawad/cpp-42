#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
    public:
		ScavTrap();
		ScavTrap(std::string &n);
		ScavTrap(const ScavTrap &copy);
		~ScavTrap();
		ScavTrap &operator=(const ScavTrap &obj);
		void guardGate();
		void attack(const std::string &target);
};


#endif