#include "NeedCourseCreationForm.hpp"

/*Member functions*/
void NeedCourseCreationForm::method()
{
    // Method implementation
}

/*Getters and Setters*/

/*Constructors*/
NeedCourseCreationForm::NeedCourseCreationForm(/*Parameterized Constructor*/)
{
   std::cout << "NeedCourseCreationForm parameterized constructor is called" << std::endl;
}

NeedCourseCreationForm::NeedCourseCreationForm()
{
    std::cout << "NeedCourseCreationForm default constructor is called" << std::endl;
}

/*Destructors*/
NeedCourseCreationForm::~NeedCourseCreationForm( void )
{
    std::cout << "NeedCourseCreationForm destructor is called" << std::endl;
}

/*Overload operators*/
NeedCourseCreationForm& NeedCourseCreationForm::operator=(const NeedCourseCreationForm& src)
{
	std::cout << "NeedCourseCreationForm copy assignment is called" << std::endl;
	if (this != &src)
	{
		// Assinment variables
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& output_stream, NeedCourseCreationForm& src)
{
	output_stream << "* NeedCourseCreationForm Class info*" << std::endl;
	return output_stream;
}

