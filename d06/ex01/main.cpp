#include "Serializer.hpp"

#include "Serializer.hpp"

int main()
{
	Data ptr2;
	ptr2.name = "inkonnu";
	ptr2.age = 137;
	ptr2.next = NULL;

	Data ptr;
	ptr.name = "harry maguire";
	ptr.age = 10;
	ptr.next = &ptr2;


	std::cout<<"ptr address: " << &ptr <<
	"\nptr name: " << ptr.name <<
	"\nptr age: " << ptr.age <<
	"\nptr address next: " << ptr.next << std::endl;
	std::cout << "\nptr2 address: " << &ptr2 <<
				"\nptr2 name: " << ptr2.name <<
				"\nptr2 age: " << ptr2.age <<
				"\nptr2 address next: " << ptr2.next << std::endl;

	Serializer a;

	Data *reserialized_struct = a.unserialize(a.serialize(&ptr));

		std::cout << "\nreserialized address: " << reserialized_struct <<
				"\nreserialized name: " << reserialized_struct->name <<
				"\nreserialized age: " << reserialized_struct->age <<
				"\nreserialized address next: " << reserialized_struct->next <<
	std::endl;
	std::cout << "\nptr2address: " << &ptr2 <<
				"\nptr2name: " << ptr2.name <<
				"\nptr2age: " << ptr2.age <<
				"\nptr2address next: " << ptr2.next <<
	std::endl << std::endl;

	return (0);
}