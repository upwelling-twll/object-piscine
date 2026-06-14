#include "SpecialOffice.hpp"

/*Member functions*/
void SpecialOffice::method()
{
    // Method implementation
}

/*Getters and Setters*/

/*Constructors*/
SpecialOffice::SpecialOffice(/*Parameterized Constructor*/)
{
   std::cout << "SpecialOffice parameterized constructor is called" << std::endl;
}

SpecialOffice::SpecialOffice()
{
    std::cout << "SpecialOffice default constructor is called" << std::endl;
}

/*Destructors*/
SpecialOffice::~SpecialOffice( void )
{
    std::cout << "SpecialOffice destructor is called" << std::endl;
}

/*Overload operators*/
SpecialOffice& SpecialOffice::operator=(const SpecialOffice& src)
{
	std::cout << "SpecialOffice copy assignment is called" << std::endl;
	if (this != &src)
	{
		// Assinment variables
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& output_stream, SpecialOffice& src)
{
	output_stream << "* SpecialOffice Class info*" << std::endl;
	return output_stream;
}

