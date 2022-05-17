#include "Base.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <cstdio>

static Base *generate(void)
{
	switch (rand() % 3)
	{
	case 0:
		return (new A());
		break;
	case 1:
		return (new B());
		break;
	case 2:
		return (new C());
		break;
	}
	return(NULL);
}
void
identify_from_pointer(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "0" << std::endl;
}

void identify_from_reference(Base & p)
{
	try {
		A & a = dynamic_cast<A &>(p);
		std::cout << "A"<<std::endl;
	}
	catch (std::exception &e){
	}
	try {
		B & b = dynamic_cast<B &>(p);
		std::cout << "B"<<std::endl;
	}
	catch (std::exception &e){
	}
	try {
		C & c = dynamic_cast<C &>(p);
		std::cout << "C"<<std::endl;
	}
	catch (std::exception &e){
	}
}


int main(void)
{
	srand(time(NULL));

	Base *Ptr = generate();
	Base & Ref = *Ptr;

	identify_from_pointer(Ptr);
	identify_from_reference(Ref);

	delete Ptr;
	return 0;
}