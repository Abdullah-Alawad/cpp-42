#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamnodTrap: public ScavTrap, public FragTrap
{
	private:
		std::string name;
	public:
		DiamnodTrap();
		DiamnodTrap(std::)
};

#endif