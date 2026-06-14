#include "Staff.hpp"

/*Member functions*/
void Staff::method()
{
    // Method implementation
}

/*Getters and Setters*/

/*Constructors*/
Staff::Staff(/*Parameterized Constructor*/)
{
   std::cout << "Staff parameterized constructor is called" << std::endl;
}

Staff::Staff()
{
    std::cout << "Staff default constructor is called" << std::endl;
}

/*Destructors*/
Staff::~Staff( void )
{
    std::cout << "Staff destructor is called" << std::endl;
}

/*Overload operators*/
Staff& Staff::operator=(const Staff& src)
{
	std::cout << "Staff copy assignment is called" << std::endl;
	if (this != &src)
	{
		// Assinment variables
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& output_stream, Staff& src)
{
	output_stream << "* Staff Class info*" << std::endl;
	return output_stream;
}

