// #include "Staff.hpp"
#include "Headmaster.hpp"
#include "../Debug.hpp"
#include "../objects/Course.hpp"
#include <typeinfo>
#include "../singletons.hpp"


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
	return (p_secretary.createForm<NeedCourseCreation>());
}

Form* Headmaster::subscribeToCourse()
{
	if (!p_secretary)
		LOG_WARNING("Headmaster " + this->getName() + " has no secretery. Can not proceed with the request");
	return (p_secretary.createForm<SubscriptionToCourse>());
}

Form* Headmaster::needRoom()
{	
	if (!p_secretary)
		LOG_WARNING("Headmaster " + this->getName() + " has no secretery. Can not proceed with the request");
	return (p_secretary.createForm<NeedMoreClassRoom>());
}

Form* Headmaster::finishCourse()
{
	if (!p_secretary)
		LOG_WARNING("Headmaster " + this->getName() + " has no secretery. Can not proceed with the request");
	return (p_secretary.createForm<CourseFinished>());
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

