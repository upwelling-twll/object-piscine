#include "Form.hpp"

/*Member functions*/
void Form::method()
{
    // Method implementation
}

/*Getters and Setters*/

/*Constructors*/
Form::Form(/*Parameterized Constructor*/)
{
   std::cout << "Form parameterized constructor is called" << std::endl;
}

Form::Form()
{
    std::cout << "Form default constructor is called" << std::endl;
}

/*Destructors*/
Form::~Form( void )
{
    std::cout << "Form destructor is called" << std::endl;
}

/*Overload operators*/
Form& Form::operator=(const Form& src)
{
	std::cout << "Form copy assignment is called" << std::endl;
	if (this != &src)
	{
		// Assinment variables
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& output_stream, Form& src)
{
	output_stream << "* Form Class info*" << std::endl;
	return output_stream;
}

