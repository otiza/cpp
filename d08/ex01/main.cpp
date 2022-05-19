#include "Span.hpp"

int main()
{
	{
Span a = Span(5);
a.addNumber(6);
a.addNumber(3);
a.addNumber(17);
a.addNumber(9);
a.addNumber(11);
		
		/*for (size_t i = 0; i < 6; i++)
		{
			try
			{
				a.addNumber(i);
				std::cout<<"\n"<< i << std::endl;
			}
			catch (std::exception &e)
			{
				std::cerr << std::endl << e.what() << std::endl;
			}
		}*/
		std::cout << "shortest span is " << a.shortestSpan() << std::endl;
		std::cout << "longest span is " << a.longestSpan() << std::endl;
	}
	std::cout << std::endl << "---------------------------------------------------------------" << std::endl << std::endl;
/*	{
		Span a = Span(10000);
		a.addNumber(10000, time(NULL));
		std::cout << "shortest span is " << a.shortestSpan() << std::endl;
		std::cout << "longest span is " << a.longestSpan() << std::endl << std::endl;
	}*/
	return (0);
}
