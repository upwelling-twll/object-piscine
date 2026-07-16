#include "NeedCourseCreationForm.hpp"
#include "../Debug.hpp"
#include "../singletons.hpp"

/*Member functions*/
void NeedCourseCreationForm::execute(Headmaster *hm)
{
    if (!hm)
        return;
    LOG_ACTION("NeedCourseCreationForm: executed by headmaster " + hm->getName());
    Course* newCourse = new Course(courseName, classesToGraduate, maxNumberOfStudents);
    if (newCourse)
    {
        CourseList::getSingleList().add(newCourse);
		this->_execStatus = true;
        LOG_ACTION("NeedCourseCreationForm: created course");
    }    
    else 
        LOG_WARNING("NeedCourseCreationForm:course was not created");
}   

bool NeedCourseCreationForm::isComplete()
{
    return courseNameSet && classesToGraduateSet && maxNumberOfStudentsSet;
}
/*Getters and Setters*/
void	NeedCourseCreationForm::setCourseName(std::string name)
{
    courseName = name;
    courseNameSet = true;
}

void	NeedCourseCreationForm::setClassesToGraduate(int classes)
{
    classesToGraduate = classes;
    classesToGraduateSet = true;
}

void	NeedCourseCreationForm::setNumberOfStudents(int number)
{
    maxNumberOfStudents = number;
    maxNumberOfStudentsSet = true;
}


/*Constructors*/
NeedCourseCreationForm::NeedCourseCreationForm(FormType type, time_t expirationDate) : Form(type, expirationDate)
{
    classesToGraduate = 0;
    maxNumberOfStudents = 0;
    courseNameSet= false;
    classesToGraduateSet = false;
    maxNumberOfStudentsSet = false;
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

