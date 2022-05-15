#include "Form.hpp"
Form::Form(void): name("randim"), sign(false), signreq(150), execreq(150)
{
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form &src): name(src.getName()), sign(false), signreq(src.getSignGrade()), execreq(src.getExecGrade())
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = src;
}

Form::Form(int _signreq, int _execreq): name("random"), sign(false), signreq(_signreq), execreq(_execreq)
{
	std::cout << "Form Sign and exec requirement constructor called"<<std::endl;

	const int i = this->getSignGrade();
	const int j = this->getExecGrade();
	if (i > 150 || j > 150)
		throw(Form::GradeTooLowException());
	else if( i < 1 || j < 1)
		throw(Form::GradeTooHighException());
}

Form::Form(const std::string nm): name(nm), sign(false), signreq(150), execreq(150)
{
	std::cout << "Form name Constructor called" << std::endl;
}

Form::Form(const std::string nm,  int _signreq, int _execreq): name(nm), sign(false), signreq(_signreq), execreq(_execreq)
{
	std::cout << "Form name , signe and exec requirements constructor called" << std::endl;
	const int i = this->getSignGrade();
	const int j = this->getExecGrade();
	if (i > 150 || j > 150)
		throw(Form::GradeTooLowException());
	else if( i < 1 || j < 1)
		throw(Form::GradeTooHighException());
}
Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form &Form::operator=(const Form &src)
{
	std::cout << "Form Assignement operator called" << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

void Form::beSigned(Bureaucrat &signer)
{
	if ((int)signer.getGrade() > this->getSignGrade())
		throw(Bureaucrat::GradeTooLowException());
	else if (this->getIsSigned() == "false")
	{
		this->sign = true;
		std::cout << this->getName() << " Form was signed by " << signer.getName() << std::endl;
	}
	else
		std::cout << this->getName() << " Form is already signed" << std::endl;
}

const std::string	Form::getName(void)const
{
	return (this->name);
}

const std::string	Form::getIsSigned(void)const
{
	if (this->sign)
		return ("true");
	else
		return ("false");
}

bool	Form::getIsSignedBool(void)const
{
	return (this->sign);
}

int	Form::getSignGrade(void)const
{
	return (this->signreq);
}

int	Form::getExecGrade(void)const
{
	return (this->execreq);
}
void Form::execute(Bureaucrat const &executor)const
{
	(void)executor;
}
const char *Form::FormNotSignedException::what(void) const throw()
{
	return ("form need to be signed");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return (" Grade too low");
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

std::ostream	&operator<<(std::ostream &o, Form *a)
{
	o << "Form " << a->getName() <<
	"\nsign-grade: " << a->getSignGrade() <<
	"\nexec-grade: " << a->getExecGrade() <<
	"\nis signed: " << a->getIsSigned() <<
	std::endl;
	return (o);
}