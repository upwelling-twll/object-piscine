#include "NeedCourseCreationForm.hpp"
#include "../Debug.hpp"

/*Member functions*/
void NeedCourseCreationForm::execute()
{
    // Method implementation
}

/*Getters and Setters*/

/*Constructors*/
NeedCourseCreationForm::NeedCourseCreationForm(FormType type) : Form(type)
{
    LOG_CTOR("NeedCourseCreationForm parameterized constructor is called");
}

/*Destructors*/
NeedCourseCreationForm::~NeedCourseCreationForm( void )
{
    LOG_DTOR("NeedCourseCreationForm destructor is called");
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, NeedCourseCreationForm& src)
{
	output_stream << "* NeedCourseCreationForm Class info*" << std::endl;
	output_stream << " Sign status: " << src.getSignStatus() << std::endl;
	output_stream << " Execution status: " << src.getExecStatus() << std::endl;
    return output_stream;
}

