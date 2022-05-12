#pragma once


#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	private:
		bool gk;
	public:

		ScavTrap();
		ScavTrap(const ScavTrap &copy);
		ScavTrap(std::string name);

		virtual ~ScavTrap();
		ScavTrap &operator=(const ScavTrap &src);
		void attack(const std::string &target);
		void guardGate(void);
};