#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << "CLAPTRAP\n" << std::endl;
	{
		
		ClapTrap a;
		ClapTrap b("Cody");
		a.attack("khouna");
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		a.attack("khouna");
		b.beRepaired(3);
		b.beRepaired(3);
	}
	std::cout << "\n\nSCAVTRAP\n" << std::endl;
	{

		ScavTrap c;
		ScavTrap d("WA7CH");

		std::cout << "Testing" << std::endl;
		c.attack("an");
		c.beRepaired(22);
		c.takeDamage(21);
		c.beRepaired(22);
		c.guardGate();
		c.guardGate();
		d.attack("ab");
		d.takeDamage(101);
		d.takeDamage(15);
		d.attack("ab");
		
	}
	std::cout << "\n\nFRAGTRAP\n" << std::endl;
	{

		FragTrap e;
		FragTrap f("noah");

	
		e.highFiveGuys();
		e.attack("some random dude");
		e.takeDamage(101);
		e.takeDamage(1);
		e.attack("some random dude");
		f.highFiveGuys();


		
		
	}
	return (0);
}
