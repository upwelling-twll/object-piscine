#include "SubscriptionToCourseForm.hpp"

/*Member functions*/
void SubscriptionToCourseForm::method()
{
    // Method implementation
}

/*Getters and Setters*/

/*Constructors*/
SubscriptionToCourseForm::SubscriptionToCourseForm(/*Parameterized Constructor*/)
{
   std::cout << "SubscriptionToCourseForm parameterized constructor is called" << std::endl;
}

SubscriptionToCourseForm::SubscriptionToCourseForm()
{
    std::cout << "SubscriptionToCourseForm default constructor is called" << std::endl;
}

/*Destructors*/
SubscriptionToCourseForm::~SubscriptionToCourseForm( void )
{
    std::cout << "SubscriptionToCourseForm destructor is called" << std::endl;
}

/*Overload operators*/
SubscriptionToCourseForm& SubscriptionToCourseForm::operator=(const SubscriptionToCourseForm& src)
{
	std::cout << "SubscriptionToCourseForm copy assignment is called" << std::endl;
	if (this != &src)
	{
		// Assinment variables
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& output_stream, SubscriptionToCourseForm& src)
{
	output_stream << "* SubscriptionToCourseForm Class info*" << std::endl;
	return output_stream;
}

