
#include "ClapTrap.hpp"
int main()
{
    ClapTrap		not_claptrap("'a good name'");
	not_claptrap.beRepaired(10);
	not_claptrap.takeDamage(10);
	not_claptrap.takeDamage(100);
	not_claptrap.attack("ali");
	not_claptrap.attack("ali");

}