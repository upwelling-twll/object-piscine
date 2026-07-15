#include "Staff.hpp"
#include "Secretary.hpp"
#include "../forms/forms.hpp"
#include "../Debug.hpp"
#include "../rooms/SecretarialOffice.hpp"
#include "../singletonTypedefs.hpp"
#include <memory>

/*Member functions*/
// void Secretary::update(Break _break)
// {
// 	LOG_DBUG(this->getName() + " received the bell signal");
//     switch (_break)
//     {
//         case Break::BreakStarted:
// 		{
// 			_previousRoom = _currentRoom;
// 			if (_currentRoom != NULL)
// 				_currentRoom->exit(this);
// 			_currentRoom = NULL;
//             break;
// 		}

//         case Break::BreakEnded:
// 		{
// 			if (_previousRoom != NULL)
// 				_previousRoom->enter(this);
// 			_currentRoom = _previousRoom;
// 			break;
// 		}
//     }
// }


std::unique_ptr<Form> Secretary::createForm(FormType p_formType, time_t expiration)
{
	if (p_formType == FormType::CourseFinished)
		return std::make_unique<CourseFinishedForm>(p_formType, expiration);
	if (p_formType == FormType::NeedMoreClassRoom)
		return std::make_unique<NeedMoreClassRoomForm>(p_formType, expiration);
	if (p_formType == FormType::NeedCourseCreation)
		return std::make_unique<NeedCourseCreationForm>(p_formType, expiration);
	if (p_formType == FormType::SubscriptionToCourse)
		return std::make_unique<SubscriptionToCourseForm>(p_formType, expiration);
	return (NULL);
}

void Secretary::archiveForm(std::unique_ptr<Form> p_form)
{
	if (!p_form)
		std::invalid_argument("Secretary archiveForm() received null form");
	else
	{
		sendFormToArchive(std::move(p_form));
	}

}

void Secretary::sendFormToArchive(std::unique_ptr<Form> p_form)
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
			sr->addToArchive(std::move(p_form));
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

