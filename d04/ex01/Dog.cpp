#include "Dog.hpp"

Dog::Dog(): Animal()
{
    std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
	if(this->brain == NULL)
	{
		std::cerr<< "allocation not completed"<< std::endl;
		exit(1);
	}
}

Dog::Dog(const Dog &copy): Animal()
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = copy;
}

Dog::~Dog()
{
	delete(this->brain);
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
	std::cout << "Dog assignement operator called" << std::endl;
	if (this == &src)
		return *this;

	this->type = src.type;
	this->brain = new Brain();
	if(this->brain == NULL)
	{
		std::cerr<< "allocation not completed"<< std::endl;
		exit(1);
	}
	*this->brain = *src.brain;
	return *this;
}

void	Dog::makeSound(void)const
{
	std::cout << this->getType() << "HOW HOW!" << std::endl;
}