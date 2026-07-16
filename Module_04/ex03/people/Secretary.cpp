#include "Staff.hpp"
#include "Secretary.hpp"
#include "../forms/forms.hpp"
#include "../Debug.hpp"
#include "../singletons.hpp"


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

void Secretary::archiveForm(Form* p_form)
{
	if (!p_form)
		std::invalid_argument("Secretary archiveForm() received null form");
	else
	{
		sendFormToArchive(p_form);
	}

}

void Secretary::sendFormToArchive(Form* p_form)
{
	int size = RoomList::getSingleList().getSize();
	SecretarialOffice* sr = NULL;
	for (int i = 0; i < size; ++i)
	{
		Room* r = RoomList::getSingleList().get(i);
		if (typeid(*r) == typeid(SecretarialOffice))
		{
			sr = dynamic_cast<SecretarialOffice*>(r);
			break;
		}
	}
	if (sr)
	{
		if (sr->canEnter(this) || this->getCurrentRoom() == sr)
		{
			sr->enter(this);
			sr->addToArchive(p_form);
			sr->exit(this);
			return;
		}
		else
			LOG_WARNING("Secretary could not enter office");
	}
	else
		LOG_WARNING("Secretary could not find archive");
}


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

