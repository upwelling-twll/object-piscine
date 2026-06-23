#include "Form.hpp"
#include "../Debug.hpp"

/*Member functions*/


/*Getters and Setters*/

/*Constructors*/
Form::Form(FormType p_formType) : _formType(p_formType)
{
    LOG_CTOR("Form parameterized constructor is called");
}

/*Destructors*/
Form::~Form( void )
{
    LOG_DTOR("Form destructor is called");
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, Form& src)
{
	output_stream << "* Form Class info*" << std::endl;
	return output_stream;
}

