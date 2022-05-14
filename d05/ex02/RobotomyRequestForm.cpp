#include "RobotomyRequestForm.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm(): Form("RobotomyRequestForm", 72, 45), target("random")
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string trgt): Form("RobotomyRequestForm", 72, 45), target(trgt)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &src): Form("RobotomyRequestForm", 72, 45), target(src.getTarget())
{
	std::cout << "RobotomyRequestForm copy constructor called to copy " << std::endl;

	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

// Overloaded Operators
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	std::cout << "RobotomyRequestForm assignement operator called" << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

static int robotized = 0;


void	RobotomyRequestForm::execute(Bureaucrat const &executor)const
{
	if ((int)executor.getGrade() > this->getExecGrade())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getIsSignedBool() == false)
		throw (Form::FormNotSignedException());
	else if (robotized++ % 2)
		std::cout << "GRGRGRGRGRGRGRGRGRGR\n" << this->getTarget() << " was robotomized" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}

// Getter
std::string	RobotomyRequestForm::getTarget(void)const
{
	return (this->target);
}

// Setter

// ostream Overload
std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm *a)
{
	o << "Form " << a->getName() <<
	"\nsign-grade:" << a->getSignGrade() <<
	"\nexec-grade:" << a->getExecGrade() <<
	"\nis signed:" << a->getIsSigned() <<
	std::endl;
	return (o);
}
