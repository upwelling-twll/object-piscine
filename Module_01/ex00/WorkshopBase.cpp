#include "WorkshopBase.hpp"

/*Member functions*/
void WorkshopBase::method()
{
    // Method implementation
}

/*Getters and Setters*/

/*Constructors*/
WorkshopBase::WorkshopBase(/*Parameterized Constructor*/)
{
   std::cout << "WorkshopBase parameterized constructor is called" << std::endl;
}

WorkshopBase::WorkshopBase()
{
    std::cout << "WorkshopBase default constructor is called" << std::endl;
}

/*Destructors*/
WorkshopBase::~WorkshopBase( void )
{
    std::cout << "WorkshopBase destructor is called" << std::endl;
}

/*Overload operators*/
WorkshopBase& WorkshopBase::operator=(const WorkshopBase& src)
{
	std::cout << "WorkshopBase copy assignment is called" << std::endl;
	if (this != &src)
	{
		// Assinment variables
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& output_stream, WorkshopBase& src)
{
	output_stream << "* WorkshopBase Class info*" << std::endl;
	return output_stream;
}

