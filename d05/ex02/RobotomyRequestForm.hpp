#pragma once

#include <string>
#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "Form.hpp"

// classes

class Bureaucrat;

class From;

class RobotomyRequestForm: public Form
{
	private:
		const std::string target;
		RobotomyRequestForm(void);
	public:

		RobotomyRequestForm(std::string trgt);
		RobotomyRequestForm(RobotomyRequestForm &src);

		~RobotomyRequestForm();

		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

		void execute(Bureaucrat const &executor)const;

		std::string getTarget(void)const;


};

// // ostream Overload
std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm *a);