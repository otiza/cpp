#pragma once
#include "Bureaucrat.hpp"

#include <string>
#include <iostream>
class Bureaucrat;
class Form
{
	private:
		const std::string name;
		bool sign;
		const int signreq;
		const int execreq;

	public:

		Form(void);
		Form(const Form &src);
		Form(int _signreq, int _execreq);
		Form(const std::string nm);
		Form(const std::string nm, int _signreq, int _execreq);

		Form &operator=(const Form &src);

		void beSigned(Bureaucrat &signer);
		const std::string getName(void)const;
		const std::string getIsSigned(void)const;
		bool getIsSignedBool(void)const;
		int getSignGrade(void)const;
		int getExecGrade(void)const;
    	virtual ~Form();
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};


	virtual void execute(Bureaucrat const &executor)const = 0;
};

std::ostream	&operator<<(std::ostream &o, Form *a);
