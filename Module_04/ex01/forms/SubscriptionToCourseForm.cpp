#include "SubscriptionToCourseForm.hpp"
#include "../Debug.hpp"

/*Member functions*/
void SubscriptionToCourseForm::execute()
{
    // Method implementation
}

/*Getters and Setters*/

/*Constructors*/
SubscriptionToCourseForm::SubscriptionToCourseForm(FormType type) : Form(type)
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
	return output_stream;
}

