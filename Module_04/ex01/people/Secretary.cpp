#include "Secretary.hpp"

/*Member functions*/
void Secretary::method()
{
    // Method implementation
}

/*Getters and Setters*/

/*Constructors*/
Secretary::Secretary(/*Parameterized Constructor*/)
{
   std::cout << "Secretary parameterized constructor is called" << std::endl;
}

Secretary::Secretary()
{
    std::cout << "Secretary default constructor is called" << std::endl;
}

/*Destructors*/
Secretary::~Secretary( void )
{
    std::cout << "Secretary destructor is called" << std::endl;
}

/*Overload operators*/
Secretary& Secretary::operator=(const Secretary& src)
{
	std::cout << "Secretary copy assignment is called" << std::endl;
	if (this != &src)
	{
		// Assinment variables
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& output_stream, Secretary& src)
{
	output_stream << "* Secretary Class info*" << std::endl;
	return output_stream;
}

