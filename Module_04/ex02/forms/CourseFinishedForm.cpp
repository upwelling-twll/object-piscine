#include "CourseFinishedForm.hpp"
#include "../courses/Course.hpp"
#include "../people/Headmaster.hpp"

/*Member functions*/
void CourseFinishedForm::execute(Headmaster *hm)
{
	if (!hm)
		LOG_WARNING("CourseFinishedForm: headmaster is null, can not execute");
	else if (!p_course)
		LOG_WARNING("CourseFinishedForm: p_course is null, can not execute");
	else
	{
		p_course->setFinished();
		this->_execStatus = true;
		//TODO maybe course should unsubscribe students or/and removed from vector
		LOG_ACTION("CourseFinishedForm: course " + p_course->getName() + " was finished");
	}
}

bool CourseFinishedForm::isComplete()
{
	return (courseSet);
}

/*Getters and Setters*/
void	CourseFinishedForm::setCourse(Course* course)
{
	p_course = course;
	courseSet = true;
}


/*Constructors*/
CourseFinishedForm::CourseFinishedForm(FormType type, time_t expirationDate) : Form(type, expirationDate)
{
	courseSet = false;
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

