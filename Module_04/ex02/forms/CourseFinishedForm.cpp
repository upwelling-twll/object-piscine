#include "CourseFinishedForm.hpp"

/*Member functions*/
void CourseFinishedForm::execute(Headmaster *hm)
{
	(void)hm;
}
/*Getters and Setters*/

/*Constructors*/
CourseFinishedForm::CourseFinishedForm(FormType type, time_t expirationDate) : Form(type, expirationDate)
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
	output_stream << " Sign status: " << src.getSignStatus() << std::endl;
	output_stream << " Execution status: " << src.getExecStatus() << std::endl;
    return output_stream;
}

