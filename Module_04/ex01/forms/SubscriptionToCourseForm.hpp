#ifndef SUBSCRIPTIONTOCOURSEFORM_HPP
# define SUBSCRIPTIONTOCOURSEFORM_HPP

# include <iostream>
# include "Form.hpp"

class SubscriptionToCourseForm : public Form
{
private:
    // Add member variables here

public:
	/*Member functions*/
   void execute();

	/*Getters and Setters*/

	/*Constructors*/
    SubscriptionToCourseForm(FormType type);

	/*Destructors*/
    ~SubscriptionToCourseForm( void );

	// /*Overload operators*/
};

std::ostream& operator<<(std::ostream &output_stream, SubscriptionToCourseForm& src);

#endif // SUBSCRIPTIONTOCOURSEFORM_HPP
