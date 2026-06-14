#include "Person.hpp"

/*Member functions*/
void Person::method()
{
    // Method implementation
}

/*Getters and Setters*/

/*Constructors*/
Person::Person(/*Parameterized Constructor*/)
{
   std::cout << "Person parameterized constructor is called" << std::endl;
}

Person::Person()
{
    std::cout << "Person default constructor is called" << std::endl;
}

/*Destructors*/
Person::~Person( void )
{
    std::cout << "Person destructor is called" << std::endl;
}

/*Overload operators*/
Person& Person::operator=(const Person& src)
{
	std::cout << "Person copy assignment is called" << std::endl;
	if (this != &src)
	{
		// Assinment variables
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& output_stream, Person& src)
{
	output_stream << "* Person Class info*" << std::endl;
	return output_stream;
}

