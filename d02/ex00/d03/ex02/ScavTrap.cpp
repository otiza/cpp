#include "ScavTrap.hpp"


ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "ScavTrap Default Constructor called" << std::endl;
    this->hp = 100;
	this->ep = 50;
	this->dmg = 20;
	this->gk = false;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{
    std::cout << "ScavTrap Copy Constructor called" << std::endl;
    this->gk = copy.gk;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    std::cout << "ScavTrap for the name Constructor  " << this->name << " called" << std::endl;
	this->hp = 100;
	this->ep = 50;
	this->dmg = 20;
	this->gk = false;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor for " << " called" << std::endl;
}
void	ScavTrap::attack(const std::string &target)
{
	if (this->ep > 0 && this->hp > 0)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->dmg << " points of damage!" << std::endl;
		this->ep--;
	}
	else if (this->ep == 0)
		std::cout << "ScavTrap " << this->name << " is not able to attack " << target << ", because he has no energy points left" << std::endl;
	else
		std::cout << "ScavTrap " << this->name << " is not able to attack " << target << ", because he has not enough hit points" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (this->gk == false)
	{
		this->gk = true;
		std::cout << "ScavTrap " << this->name << " is gate guarding" << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->name << " is already gate guarding" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "ScavTrap Assignation operator called" << std::endl;
	this->name = src.name;
	this->hp = src.hp;
	this->ep = src.ep;
	this->dmg = src.dmg;
	return *this;
}