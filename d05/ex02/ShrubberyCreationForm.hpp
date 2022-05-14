#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class Bureaucrat;

class From;

class ShrubberyCreationForm: public Form
{
	private:
		const std::string target;

		ShrubberyCreationForm(void);
	public:
		ShrubberyCreationForm(std::string trgt);
		ShrubberyCreationForm(ShrubberyCreationForm &src);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
		void execute(Bureaucrat const &executor)const;
		std::string getTarget(void)const;

};

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm *a);
