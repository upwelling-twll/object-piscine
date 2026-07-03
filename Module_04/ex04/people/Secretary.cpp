#include "Staff.hpp"
#include "Secretary.hpp"
#include "../forms/forms.hpp"
#include "../Debug.hpp"

/*Member functions*/
Form* Secretary::createForm(FormType p_formType, time_t expiration)
{
	if (p_formType == FormType::CourseFinished)
		return (new CourseFinishedForm(p_formType, expiration));
	if (p_formType == FormType::NeedMoreClassRoom)
		return (new NeedMoreClassRoomForm(p_formType, expiration));
	if (p_formType == FormType::NeedCourseCreation)
		return (new NeedCourseCreationForm(p_formType, expiration));
	if (p_formType == FormType::SubscriptionToCourse)
		return (new SubscriptionToCourseForm(p_formType, expiration));
    return (NULL);
}

// void Secretary::archiveForm()
// {

// }

/*Getters and Setters*/

/*Constructors*/
Secretary::Secretary(std::string name) : Staff(name)
{
	LOG_CTOR("Secretary parameterized constructor is called");
}

/*Destructors*/
Secretary::~Secretary( void )
{
	LOG_DTOR("Secretary destructor is called");
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, Secretary& src)
{
	output_stream << "* Secretary Class info*" << std::endl;
	output_stream << src.getName() << std::endl;
    Room* currentRoom;
	currentRoom = src.getCurrentRoom();
    if (currentRoom == NULL)
		output_stream << "Current Room: null" << std::endl;
	else
		output_stream << "Current Room: " << currentRoom->getRoomNumber() << std::endl;
  
    return output_stream;
}

