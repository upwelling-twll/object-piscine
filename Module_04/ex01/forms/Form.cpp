#include "Form.hpp"

/*Member functions*/


/*Getters and Setters*/

/*Constructors*/
Form::Form(FormType p_formType) : _formType(p_formType)
{
   std::cout << "Form parameterized constructor is called" << std::endl;
}

/*Destructors*/
Form::~Form( void )
{
    std::cout << "Form destructor is called" << std::endl;
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, Form& src)
{
	output_stream << "* Form Class info*" << std::endl;
	return output_stream;
}

