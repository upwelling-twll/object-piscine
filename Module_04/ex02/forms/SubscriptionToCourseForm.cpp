#include "SubscriptionToCourseForm.hpp"
#include "../Debug.hpp"
#include "../people/Student.hpp"
#include "../objects/Course.hpp"


/*Member functions*/
void SubscriptionToCourseForm::execute(Headmaster *hm)
{
   if (!hm)
		LOG_WARNING("SubscriptionToCourseForm: headmaster is null, can not execute");
	else if (!p_course)
		LOG_WARNING("SubscriptionToCourseForm: p_course is null, can not execute");
	else if (!p_course)
		LOG_WARNING("SubscriptionToCourseForm: p_student is null, can not execute");
    else
	{
		p_course->addStudent();
        p_student->addCourse();
		this->_execStatus = true;
		//TODO maybe course should unsubscribe students or/and removed from vector
		LOG_ACTION("SubscriptionToCourseForm: student " + p_student->getName() + " subscribed to " p_course->getName());
	}
}

/*Getters and Setters*/

/*Constructors*/
SubscriptionToCourseForm::SubscriptionToCourseForm(FormType type, time_t expirationDate) : Form(type, expirationDate)
{
    LOG_CTOR("SubscriptionToCourseForm parameterized constructor is called");
}

/*Destructors*/
SubscriptionToCourseForm::~SubscriptionToCourseForm( void )
{
    LOG_DTOR("SubscriptionToCourseForm destructor is called");
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, SubscriptionToCourseForm& src)
{
	output_stream << "* SubscriptionToCourseForm Class info*" << std::endl;
	output_stream << " Sign status: " << src.getSignStatus() << std::endl;
	output_stream << " Execution status: " << src.getExecStatus() << std::endl;
    return output_stream;
}

