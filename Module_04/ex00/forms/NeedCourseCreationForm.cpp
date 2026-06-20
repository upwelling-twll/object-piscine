#include "NeedCourseCreationForm.hpp"

/*Member functions*/
void NeedCourseCreationForm::execute()
{
    // Method implementation
}

/*Getters and Setters*/

/*Constructors*/
NeedCourseCreationForm::NeedCourseCreationForm(FormType type) : Form(type)
{
   std::cout << "NeedCourseCreationForm parameterized constructor is called" << std::endl;
}

/*Destructors*/
NeedCourseCreationForm::~NeedCourseCreationForm( void )
{
    std::cout << "NeedCourseCreationForm destructor is called" << std::endl;
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, NeedCourseCreationForm& src)
{
	output_stream << "* NeedCourseCreationForm Class info*" << std::endl;
	return output_stream;
}

