#include "Animal.hpp"


Animal::Animal():type("undifined")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
	std::cout << "Assignement operator called" << std::endl;
	if (this == &src)
		return *this;
	this->type = src.type;
	return *this;
}

void Animal::makeSound(void)const
{
	std::cout << "no sound."<< std::endl;
}

std::string	Animal::getType(void)const
{
	return (this->type);
}