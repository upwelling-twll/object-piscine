// #include "Staff.hpp"
#include "Headmaster.hpp"
#include "../Debug.hpp"
#include "../objects/Course.hpp"


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

void Headmaster::addCourse(Course* p_course)
{
	if (p_course)
	{
		for (std::vector<Course*>::iterator it = _courses.begin(); it != _courses.end(); ++it)
		{
			if (*it == p_course)
			{
				LOG_WARNING("Headmaster: course is already added to list");
				return;
			}
		}
		_courses.push_back(p_course);
	}
	else
		LOG_WARNING("Headmaster: null course can not be added to list");
}

void Headmaster::removeCourse(Course* p_course)
{
	LOG_DBUG("Headmaster remove(): method started");
	LOG_DBUG("Headmaster remove(): coourse name to be removed is" + p_course->getName());

	if (p_course)
	{
		for (std::vector<Course*>::iterator it = _courses.begin(); it != _courses.end(); ++it)
		{
			if (*it == p_course)
			{
				LOG_DBUG("Headmaster remove(): found p_course in vector");
				_courses.erase(it);
				break;
			}
			if (it == _courses.end())
				LOG_WARNING("Headmaster: course is not found in the list");
		}
	}
	else
		LOG_WARNING("Headmaster: course is null, can not be removed");
}

/*Getters and Setters*/
std::vector<Course*> Headmaster::getCourses()
{
	return (_courses);
}

/*Constructors*/
Headmaster::Headmaster(std::string name) : Staff(name)
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

