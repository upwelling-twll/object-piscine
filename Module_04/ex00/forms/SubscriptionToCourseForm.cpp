#include "SubscriptionToCourseForm.hpp"

/*Member functions*/
void SubscriptionToCourseForm::execute()
{
    // Method implementation
}

/*Getters and Setters*/

/*Constructors*/
SubscriptionToCourseForm::SubscriptionToCourseForm(FormType type) : Form(type)
{
   std::cout << "SubscriptionToCourseForm parameterized constructor is called" << std::endl;
}

/*Destructors*/
SubscriptionToCourseForm::~SubscriptionToCourseForm( void )
{
    std::cout << "SubscriptionToCourseForm destructor is called" << std::endl;
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, SubscriptionToCourseForm& src)
{
	output_stream << "* SubscriptionToCourseForm Class info*" << std::endl;
	return output_stream;
}

