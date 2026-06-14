#include "Professor.hpp"

/*Member functions*/
void Professor::method()
{
    // Method implementation
}

/*Getters and Setters*/

/*Constructors*/
Professor::Professor(/*Parameterized Constructor*/)
{
   std::cout << "Professor parameterized constructor is called" << std::endl;
}

Professor::Professor()
{
    std::cout << "Professor default constructor is called" << std::endl;
}

/*Destructors*/
Professor::~Professor( void )
{
    std::cout << "Professor destructor is called" << std::endl;
}

/*Overload operators*/
Professor& Professor::operator=(const Professor& src)
{
	std::cout << "Professor copy assignment is called" << std::endl;
	if (this != &src)
	{
		// Assinment variables
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& output_stream, Professor& src)
{
	output_stream << "* Professor Class info*" << std::endl;
	return output_stream;
}

