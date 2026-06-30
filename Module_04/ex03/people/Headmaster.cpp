// #include "Staff.hpp"
#include <typeinfo>
#include "Headmaster.hpp"
#include "../Debug.hpp"
#include "../courses/Course.hpp"
#include "../singletons.hpp"
#include "../FormType.hpp"

/*Member functions*/
void Headmaster::receiveForm(Form* p_form)
{
    if (! p_form)
		throw(std::invalid_argument("Headmaster: null form can not be received."));
	else
	{
		for (std::vector<Form*>::iterator it = _formToValidate.begin(); it != _formToValidate.end(); ++it)
		{
			if (*it == p_form)
			{
				std::cout << "Headmaster: form is already received." << std::endl;
				return;
			}
		}
		_formToValidate.push_back(p_form);
	}
	sign(p_form);
	execute(p_form);
}

void Headmaster::sign(Form* p_form)
{
	p_form->beSigned();
	LOG_ACTION("Form signed by " + this->getName());   
}

void Headmaster::execute(Form* p_form)
{
	if (p_form->getSignStatus())
		p_form->execute(this);
	else
		LOG_WARNING("Headmaster won't execute anapproved form");
}

void Headmaster::launchCourses()
{
	int size = StaffList::getSingleList().getSize();
	LOG_DBUG("Headmaster: staff list size = " + std::to_string(size));
	LOG_ACTION("Headmaster: launching courses");
	for (int i = 0; i != size; ++i)
	{
		Staff* s = StaffList::getSingleList().get(i);
		if (typeid(*s) == typeid(Professor))
		{
			Professor* p = dynamic_cast<Professor*>(s);
			LOG_DBUG("Headmaster:found professor " + p->getName());
			p->doClass();
		}
	}
}

//requests from staff & students
Form* Headmaster::needCourse()
{
	if (!p_secretary)
		LOG_WARNING("Headmaster " + this->getName() + " has no secretery. Can not proceed with the request");
	time_t et = time(0) + (3600 * 24); //24 hours from now
	return (p_secretary->createForm(FormType::NeedCourseCreation, et));
}

Form* Headmaster::subscribeToCourse()
{
	if (!p_secretary)
		LOG_WARNING("Headmaster " + this->getName() + " has no secretery. Can not proceed with the request");
	time_t et = time(0) + (3600 * 24); //24 hours from now
	return (p_secretary->createForm(FormType::SubscriptionToCourse, et));
}

NeedMoreClassRoomForm* Headmaster::needRoom()
{	
	if (!p_secretary)
		LOG_WARNING("Headmaster " + this->getName() + " has no secretery. Can not proceed with the request");
	time_t et = time(0) + (3600 * 24); //24 hours from now
	return (dynamic_cast<NeedMoreClassRoomForm*>(p_secretary->createForm(FormType::NeedMoreClassRoom, et)));
}

Form* Headmaster::finishCourse()
{
	if (!p_secretary)
		LOG_WARNING("Headmaster " + this->getName() + " has no secretery. Can not proceed with the request");
	time_t et = time(0) + (3600 * 24); //24 hours from now
	return (p_secretary->createForm(FormType::CourseFinished, et));
}

/*Getters and Setters*/
void Headmaster::setSecretary(Secretary* s)
{
	p_secretary = s;
}


/*Constructors*/
Headmaster::Headmaster(std::string name) : Staff(name), p_secretary(NULL)
{
	LOG_CTOR("Headmaster parameterized constructor is called");
}

/*Destructors*/
Headmaster::~Headmaster( void )
{
	LOG_DTOR("Headmaster destructor is called");
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, Headmaster& src)
{
	output_stream << "* Headmaster Class info*" << std::endl;
	output_stream << "Name: " << src.getName() << std::endl;
	Room* currentRoom;
	currentRoom = src.getCurrentRoom();
    if (currentRoom == NULL)
		output_stream << "Current Room: null" << std::endl;
	else
		output_stream << "Current Room: " << currentRoom->getRoomNumber() << std::endl;
  
	return output_stream;
}

