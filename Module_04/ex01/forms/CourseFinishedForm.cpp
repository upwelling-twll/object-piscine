#include "CourseFinishedForm.hpp"

/*Member functions*/
void CourseFinishedForm::execute()
{
	
}
/*Getters and Setters*/

/*Constructors*/
CourseFinishedForm::CourseFinishedForm(FormType type) : Form(type)
{
   LOG_CTOR("CourseFinishedForm parameterized constructor is called");
}

/*Destructors*/
CourseFinishedForm::~CourseFinishedForm( void )
{
    LOG_DTOR("CourseFinishedForm destructor is called");
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, CourseFinishedForm& src)
{
	output_stream << "* CourseFinishedForm Class info*" << std::endl;
	return output_stream;
}

