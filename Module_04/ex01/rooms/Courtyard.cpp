#include "Courtyard.hpp"

/*Member functions*/
void Courtyard::method()
{
    // Method implementation
}

/*Getters and Setters*/

/*Constructors*/
Courtyard::Courtyard(/*Parameterized Constructor*/)
{
   std::cout << "Courtyard parameterized constructor is called" << std::endl;
}

Courtyard::Courtyard()
{
    std::cout << "Courtyard default constructor is called" << std::endl;
}

/*Destructors*/
Courtyard::~Courtyard( void )
{
    std::cout << "Courtyard destructor is called" << std::endl;
}

/*Overload operators*/
Courtyard& Courtyard::operator=(const Courtyard& src)
{
	std::cout << "Courtyard copy assignment is called" << std::endl;
	if (this != &src)
	{
		// Assinment variables
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& output_stream, Courtyard& src)
{
	output_stream << "* Courtyard Class info*" << std::endl;
	return output_stream;
}

