#include "CourseFinishedForm.hpp"

/*Member functions*/
void CourseFinishedForm::execute()
{
	
}
/*Getters and Setters*/

/*Constructors*/
CourseFinishedForm::CourseFinishedForm(FormType type) : Form(type)
{
   std::cout << "CourseFinishedForm parameterized constructor is called" << std::endl;
}

/*Destructors*/
CourseFinishedForm::~CourseFinishedForm( void )
{
    std::cout << "CourseFinishedForm destructor is called" << std::endl;
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, CourseFinishedForm& src)
{
	output_stream << "* CourseFinishedForm Class info*" << std::endl;
	return output_stream;
}

