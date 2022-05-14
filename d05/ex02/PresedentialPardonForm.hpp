#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class Bureaucrat;

class From;

class PresidentialPardonForm: public Form
{
	private:
		const std::string target;
	
		PresidentialPardonForm(void);
	public:

		PresidentialPardonForm(std::string trgt);
		PresidentialPardonForm(PresidentialPardonForm &src);

		~PresidentialPardonForm();

		PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

		void execute(Bureaucrat const &executor)const;

		std::string getTarget(void)const;

};

// // ostream Overload
std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm *a);
