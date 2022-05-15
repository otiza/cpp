#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): Form("ShrubberyCreationForm", 145, 137), target("random")
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string trgt): Form("ShrubberyCreationForm", 145, 137), target(trgt)
{
	std::cout << "ShrubberyCreationForm target constructor for target called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &src): Form("ShrubberyCreationForm", 145, 137), target(src.getTarget())
{
	std::cout << "ShrubberyCreationForm copy Constructor called to copy " << std::endl;

	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}


ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	std::cout << "ShrubberyCreationForm assignement operator called" << std::endl;
	if (this == &src)
		return *this;

	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor)const
{
	if ((int)executor.getGrade() > this->getExecGrade())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getIsSignedBool() == false)
		throw (Form::FormNotSignedException());
	else
	{
		std::ofstream outfile (this->getTarget().append("_shrubbery").c_str());

		for (int i = 0; i < 5; i++)
		{
			outfile <<
			"                     .                           " << std::endl <<
			"                     M                           " << std::endl <<
			"                    dM                           " << std::endl <<
			"                    MMr                          " << std::endl <<
			"                   4MMML                  .      " << std::endl <<
			"                   MMMMM.                xf      " << std::endl <<
			"   .               MMMMM               .MM-      " << std::endl <<
			"    Mh..          +MMMMMM            .MMMM       " << std::endl <<
			"    .MMM.         .MMMMML.          MMMMMh       " << std::endl <<
			"     )MMMh.        MMMMMM         MMMMMMM        " << std::endl <<
			"      3MMMMx.     'MMMMMMf       xnMMMMMM        " << std::endl <<
			"      '*MMMMM      MMMMMM.      nMMMMMMP         " << std::endl <<
			"        *MMMMMx    MMMMMM;     .MMMMMMM=         " << std::endl << 
			"         *MMMMMh   ;MMMMM;    JMMMMMMP           " << std::endl <<
			"           MMMMMM   3MMMM.   dMMMMMM            ." << std::endl <<
			"            MMMMMM  MMMM;   .MMMMM(         .nnMP" << std::endl <<
			" =..         *MMMMx  MMM   dMMMM        .nnMMMMM*" << std::endl <<
			"  MMn...     'MMMMr  'MM   MMMM     .nMMMMMMM*   " << std::endl <<
			"   4MMMMnn..   *MMM   MM  MMP    .dMMMMMMMMM     " << std::endl <<
			"     ^MMMMMMMMx.  *ML M  .M*  .MMMMMM***         " << std::endl <<
			"        *PMMMMMMhn. *x >  M  .MMMM**             " << std::endl <<
			"            **MMMMhx/.h/  .=*                    " << std::endl <<
			"                    .PP;%....                    " << std::endl;

		}
		outfile.close();
	}
}

std::string	ShrubberyCreationForm::getTarget(void)const
{
	return (this->target);
}

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm *a)
{
	o << "Form " << a->getName() <<
	"\nsign-grade: " << a->getSignGrade() <<
	"\nexec-grade: " << a->getExecGrade() <<
	"\nis signed: " << a->getIsSigned() <<
	std::endl;
	return (o);
}