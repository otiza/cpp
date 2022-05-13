#include "Cat.hpp"

Cat::Cat(): Animal()
{
    std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
	if(this->brain == NULL)
	{
		std::cerr<< "allocation not completed"<< std::endl;
		exit(1);
	}
}

Cat::Cat(const Cat &copy): Animal()
{
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = copy;
}

Cat::~Cat()
{
	delete(this->brain);
	std::cout << "Cat Destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Cat Assignement operator called" << std::endl;
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

void	Cat::makeSound(void)const
{
	std::cout << this->getType() << "MEOW MEOW" << std::endl;
}