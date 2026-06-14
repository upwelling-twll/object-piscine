#include "Course.hpp"

/*Member functions*/
void Course::method()
{
    // Method implementation
}

/*Getters and Setters*/

/*Constructors*/
Course::Course(/*Parameterized Constructor*/)
{
   std::cout << "Course parameterized constructor is called" << std::endl;
}

Course::Course()
{
    std::cout << "Course default constructor is called" << std::endl;
}

/*Destructors*/
Course::~Course( void )
{
    std::cout << "Course destructor is called" << std::endl;
}

/*Overload operators*/
Course& Course::operator=(const Course& src)
{
	std::cout << "Course copy assignment is called" << std::endl;
	if (this != &src)
	{
		// Assinment variables
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& output_stream, Course& src)
{
	output_stream << "* Course Class info*" << std::endl;
	return output_stream;
}

