#include "NeedCourseCreationForm.hpp"
#include "../Debug.hpp"
#include "../singletons.hpp"

/*Member functions*/
void NeedCourseCreationForm::execute(Headmaster *hm)
{
    if (!hm || _execStatus)
        return;
    LOG_ACTION("NeedCourseCreationForm: executed by headmaster " + hm->getName());
    Course* newCourse = new Course(courseName, classesToGraduate, maxNumberOfStudents);
    if (newCourse)
    {
        newCourse->assign(p_responsable);
        p_responsable->assignCourse(newCourse);
        CourseList::getSingleList().add(newCourse);
		this->_execStatus = true;
        LOG_ACTION("NeedCourseCreationForm: created course");
        LOG_INFO(*newCourse);
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

void	NeedCourseCreationForm::setResponsable(Professor* p)
{
    p_responsable = p;
}

/*Constructors*/
NeedCourseCreationForm::NeedCourseCreationForm(FormType type, time_t expirationDate) : Form(type, expirationDate)
{
    courseName = "";
	classesToGraduate = 0;
	maxNumberOfStudents = 0;
	p_responsable = NULL;
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

