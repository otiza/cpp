#pragma once


#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string type;
		Animal();

	public:

		Animal();
		Animal(const Animal &copy);
        Animal &operator=(const Animal &src);
		virtual ~Animal();
		virtual void makeSound(void)const;
		std::string getType(void)const;
};