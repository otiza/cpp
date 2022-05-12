#pragma once

#include "Animal.hpp"


class Dog: public Animal
{
	private:
	public:
		Dog();
		Dog(const Dog &copy);
		Dog &operator=(const Dog &src);
		void makeSound(void)const;
};