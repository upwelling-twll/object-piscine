#include "Headmaster.hpp"

/*Member functions*/
void Headmaster::method()
{
    // Method implementation
}

/*Getters and Setters*/

/*Constructors*/
Headmaster::Headmaster(/*Parameterized Constructor*/)
{
   std::cout << "Headmaster parameterized constructor is called" << std::endl;
}

Headmaster::Headmaster()
{
    std::cout << "Headmaster default constructor is called" << std::endl;
}

/*Destructors*/
Headmaster::~Headmaster( void )
{
    std::cout << "Headmaster destructor is called" << std::endl;
}

/*Overload operators*/
Headmaster& Headmaster::operator=(const Headmaster& src)
{
	std::cout << "Headmaster copy assignment is called" << std::endl;
	if (this != &src)
	{
		// Assinment variables
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& output_stream, Headmaster& src)
{
	output_stream << "* Headmaster Class info*" << std::endl;
	return output_stream;
}

