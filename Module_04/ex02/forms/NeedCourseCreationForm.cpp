#include "NeedCourseCreationForm.hpp"
#include "../Debug.hpp"

/*Member functions*/
void NeedCourseCreationForm::execute(Headmaster *hm)
{
    Course* newCourse = new Course(courseName, classesToGraduate, maxNumberOfStudents);
    if (newCourse)
    {
        (hm->getCourses()).push_back(newCourse);
        LOG_ACTION("NeedCourseCreationForm: created course");
    }    
    else 
        LOG_WARNING("NeedCourseCreationForm:course was not created");
}   

/*Getters and Setters*/
void	NeedCourseCreationForm::setCourseName(std::string name)
{
    courseName = name;
}

void	NeedCourseCreationForm::setClassesToGraduate(int classes)
{
    classesToGraduate = classes;
}

void	NeedCourseCreationForm::setNumberOfStudents(int number)
{
    maxNumberOfStudents = number;
}

/*Constructors*/
NeedCourseCreationForm::NeedCourseCreationForm(FormType type, time_t expirationDate) : Form(type, expirationDate)
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

