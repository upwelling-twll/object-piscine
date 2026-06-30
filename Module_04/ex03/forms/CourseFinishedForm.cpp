#include "CourseFinishedForm.hpp"
#include "../courses/Course.hpp"
#include "../people/Headmaster.hpp"
#include "../people/Student.hpp"


/*Member functions*/
void CourseFinishedForm::execute(Headmaster *hm)
{
	LOG_DBUG("Course finished form execute()");
	if (!hm)
		LOG_WARNING("CourseFinishedForm: headmaster is null, can not execute");
	else if (!p_course)
		LOG_WARNING("CourseFinishedForm: p_course is null, can not execute");
	else if (!p_student)
		LOG_WARNING("CourseFinishedForm: p_student is null, can not execute");
	else
	{
		p_course->unsubscribeStudent(p_student);
		p_student->graduate(p_course);
		this->_execStatus = true;
		//TODO maybe course should unsubscribe students or/and removed from vector
		LOG_ACTION("CourseFinishedForm: student " + p_student->getName() + " finished " + p_course->getName() + " course");
	}
}
/*Getters and Setters*/
void	CourseFinishedForm::setCourse(Course* course)
{
	p_course = course;
}

void	CourseFinishedForm::setStudent(Student* student)
{
	p_student = student;
}


/*Constructors*/
CourseFinishedForm::CourseFinishedForm(FormType type, time_t expirationDate) : Form(type, expirationDate), p_course(NULL), p_student(NULL)
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

