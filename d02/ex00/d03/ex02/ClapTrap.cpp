#include "ClapTrap.hpp"

ClapTrap::ClapTrap(/* args */)
{
    std::cout<< "ClapTrap contructor called"<< std::endl;
    this->hp= 10;
    this->ep= 10;
    this->dmg= 0;
    name =  "";
}
ClapTrap::ClapTrap(std::string nname) : name(nname) {
    std::cout<< "ClapTrap name contructor called"<< std::endl;
    this->hp= 10;
    this->ep= 10;
    this->dmg= 0;
}
ClapTrap &ClapTrap::operator=(ClapTrap const & other) {
	if (this != &other) {
		std::cout << "ClapTrap assignment operator" << std::endl;
		this->name = other.name;
		this->hp = other.hp;
		this->ep = other.ep;
		this->dmg = other.dmg;
	}
	return *this;
}
ClapTrap::~ClapTrap()
{
    std::cout<< "ClapTrap  destructor called"<< std::endl;
}
void ClapTrap::attack(const std::string& target)
{
    if (this->ep > 0 && this->hp > 0)
	{
    std::cout << "ClapTrap "<< this->name <<" attacks" << target <<" causing " << this->dmg << " points of damage" << std::endl;
    this->ep--;
    }
    else if (this->ep == 0)
		std::cout << "ClapTrap " << this->name << " is not able to attack " << target << ", because he has no energy points left" << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " is not able to attack " << target << ", because he has not enough hit points" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hp > amount)
		this->hp -= amount;
	else if (this->hp > 0)
		this->hp = 0;
    else
	{
		std::cout << "ClapTrap " << this->name << " is already dead, baraka 3lih" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " was attacked and lost " << amount << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->ep > 0 && this->hp > 0 && this->hp + amount <= 10)
	{
		this->hp += amount;
		std::cout << "ClapTrap " << this->name << " repaired itself and gained " << amount << " of hit points"  << std::endl;
		this->ep--;
	}
	else if (this->ep == 0)
		std::cout << "ClapTrap " << this->name << " is not able to repair itself, because he doesn't have enough energy points" << std::endl;
	else if (this->hp == 0)
		std::cout << "ClapTrap " << this->name << " is not able to repair itself, because he doesn't have enough hit points" << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " can't be repaired to have more than 10 hit points." << std::endl;
}

