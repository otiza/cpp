#pragma once

#include "Animal.hpp"

class Cat: public Animal
{
	private:
	public:
		Cat();
		Cat(const Cat &copy);
		~Cat();
		Cat &operator=(const Cat &src);
		void makeSound(void)const;

};