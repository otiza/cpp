
#include <string>
#include <iostream>

class ClapTrap
{

protected:
    std::string name;
    int hp;
    int ep;
    int dmg;
public:
    ClapTrap();
    ClapTrap(std::string nname);
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    ClapTrap &operator=(ClapTrap const &other);
    virtual ~ClapTrap();

};

