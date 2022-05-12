#include "FragTrap.hpp"


FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "FragTrap Default Constructor called" << std::endl;
    this->hp = 100;
	this->ep = 100;
	this->dmg = 30;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
    std::cout << "FragTrap Copy Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    std::cout << "FragTrap for the name Constructor  " << this->name << " called" << std::endl;
	this->hp = 100;
	this->ep = 100;
	this->dmg = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor for " << " called" << std::endl;
}

void	FragTrap::highFiveGuys(void)
{
	std::cout << "FragTrap " << this->name << "HIGH FIVE!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	std::cout << "Fragtrap Assignation operator called" << std::endl;
	this->name = src.name;
	this->hp = src.hp;
	this->ep = src.ep;
	this->dmg = src.dmg;
	return *this;
}
