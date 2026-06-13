#include "HeadmasterOffice.hpp"

/*Member functions*/
void HeadmasterOffice::method()
{
    // Method implementation
}

/*Getters and Setters*/

/*Constructors*/
HeadmasterOffice::HeadmasterOffice(/*Parameterized Constructor*/)
{
   std::cout << "HeadmasterOffice parameterized constructor is called" << std::endl;
}

HeadmasterOffice::HeadmasterOffice()
{
    std::cout << "HeadmasterOffice default constructor is called" << std::endl;
}

/*Destructors*/
HeadmasterOffice::~HeadmasterOffice( void )
{
    std::cout << "HeadmasterOffice destructor is called" << std::endl;
}

/*Overload operators*/
HeadmasterOffice& HeadmasterOffice::operator=(const HeadmasterOffice& src)
{
	std::cout << "HeadmasterOffice copy assignment is called" << std::endl;
	if (this != &src)
	{
		// Assinment variables
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& output_stream, HeadmasterOffice& src)
{
	output_stream << "* HeadmasterOffice Class info*" << std::endl;
	return output_stream;
}

