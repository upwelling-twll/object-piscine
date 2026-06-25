#include "SubscriptionToCourseForm.hpp"
#include "../Debug.hpp"

/*Member functions*/
void SubscriptionToCourseForm::execute()
{
    // Method implementation
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

