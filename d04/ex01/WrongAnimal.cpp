#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():type("wrongundifined")
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << "WrongAnimal Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	this->type = src.type;
	return *this;
}

void WrongAnimal::makeSound(void)const
{
	std::cout << this->getType() << "wrong undifined sound" << std::endl;
}

std::string	WrongAnimal::getType(void)const
{
	return (this->type);
}