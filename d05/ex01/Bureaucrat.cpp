#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(): name("random"), grade(150)
{
    std::cout << "Bureaucrat constructor"<< std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat &src): name(src.getName())
{
    std::cout << "Bureaucrat copy constructor"<< std::endl;
    *this = src;
}

Bureaucrat::Bureaucrat(int gd): name("random")
{
	std::cout << "Bureaucrat Grade constructor" << std::endl;
	try
	{
		this->setGrade(gd);
	}
	catch(Bureaucrat::GradeTooHighException &f)
	{
		std::cerr << "construction failed" << f.what() << std::endl <<"Grade set to 1"<< std::endl;
		this->setGrade(1);
	}
	catch(Bureaucrat::GradeTooLowException &f)
	{
		std::cerr << "Construction failed" << f.what() << std::endl <<"Grade set to 150" << std::endl;
		this->setGrade(150);
	}
}

Bureaucrat::Bureaucrat(const std::string nm): name(nm), grade(150)
{
    std::cout << "Bureaucrat name constructor"<< std::endl;
}

Bureaucrat::Bureaucrat(const std::string nm, int gd): name(nm)
{
	std::cout << "Bureaucrat Name and Grade constructor" << std::endl;
	try
	{
		this->setGrade(gd);
	}
	catch(Bureaucrat::GradeTooHighException &f)
	{
		std::cerr << "construction failed" << f.what() << std::endl <<"Grade set to 1"<< std::endl;
		this->setGrade(1);
	}
	catch(Bureaucrat::GradeTooLowException &f)
	{
		std::cerr << "Construction failed" << f.what() << std::endl <<"Grade set to 150" << std::endl;
		this->setGrade(150);
	}
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << "Bureaucrat assignement called" << std::endl;
	if (this == &src)
		return *this;
	this->grade = src.getGrade();
	return *this;
}

void	Bureaucrat::incrementGrade(void)
{
	try
	{
		std::cout << "increment grade of " << this->getName() << std::endl;
		this->setGrade(this->grade - 1);
	}
	catch(Bureaucrat::GradeTooHighException &f)
	{
		std::cerr << "increment grade fail" << f.what() << std::endl;
	}
}

void	Bureaucrat::decrementGrade(void)
{
	try
	{
		std::cout << "decrement grade of " << this->getName() << std::endl;
		this->setGrade(this->grade + 1);
	}
	catch(Bureaucrat::GradeTooLowException &f)
	{
		std::cerr << "decrement grade fail" << f.what() << std::endl;
	}
}

const std::string	Bureaucrat::getName(void)const
{
	return (this->name);
}

size_t	Bureaucrat::getGrade(void)const
{
	return (this->grade);
}
/*void	Bureaucrat::executeForm(Form &form)const
{
		form.execute(*this);
}*/
void	Bureaucrat::signForm(Form &form)
{
	form.beSigned(*this);
}
void	Bureaucrat::setGrade(int gd)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade = gd;
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};
std::ostream	&operator<<(std::ostream &o, Bureaucrat *a)
{
	o << "Bureaucrat " << a->getName() << ":\ngrade: " << a->getGrade() << std::endl;
	return (o);
}