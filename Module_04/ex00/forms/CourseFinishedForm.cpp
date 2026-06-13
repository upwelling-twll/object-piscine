#include "CourseFinishedForm.hpp"

/*Member functions*/
void CourseFinishedForm::method()
{
    // Method implementation
}

/*Getters and Setters*/

/*Constructors*/
CourseFinishedForm::CourseFinishedForm(/*Parameterized Constructor*/)
{
   std::cout << "CourseFinishedForm parameterized constructor is called" << std::endl;
}

CourseFinishedForm::CourseFinishedForm()
{
    std::cout << "CourseFinishedForm default constructor is called" << std::endl;
}

/*Destructors*/
CourseFinishedForm::~CourseFinishedForm( void )
{
    std::cout << "CourseFinishedForm destructor is called" << std::endl;
}

/*Overload operators*/
CourseFinishedForm& CourseFinishedForm::operator=(const CourseFinishedForm& src)
{
	std::cout << "CourseFinishedForm copy assignment is called" << std::endl;
	if (this != &src)
	{
		// Assinment variables
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& output_stream, CourseFinishedForm& src)
{
	output_stream << "* CourseFinishedForm Class info*" << std::endl;
	return output_stream;
}

