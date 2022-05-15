#include <string>
#include <iostream>

class Bureaucrat
{
    private:
        std::string name;
        unsigned int grade;
        void setGrade(int gd);
    public:
        Bureaucrat();
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat(int gd);
		Bureaucrat(const std::string nm);
		Bureaucrat(const std::string nm, int gd);

        Bureaucrat &operator=(const Bureaucrat &src);

		void incrementGrade(void);
		void decrementGrade(void);

		const std::string getName(void)const;
		size_t getGrade(void)const;
        ~Bureaucrat();
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
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a);