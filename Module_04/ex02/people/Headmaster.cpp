// #include "Staff.hpp"
#include "Headmaster.hpp"
#include "../Debug.hpp"
#include "../courses/Course.hpp"


/*Member functions*/
void Headmaster::receiveForm(Form* p_form)
{
    if (! p_form)
		throw(std::invalid_argument("Headmaster: null form can not be received."));
	if (!p_form->isComplete())
	{
		LOG_WARNING("Headmaster: received incomplete form. Won`t add this form to list of forms to validate");
		return;
	}
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
	if (!p_form)
		std::invalid_argument("Headmaster sign() received null form");
	else
	{
		for (std::vector<Form*>::iterator it = _formToValidate.begin(); it != _formToValidate.end(); ++it)
		{
			if (*it == p_form)
			{
				p_form->beSigned();
				LOG_ACTION("Form signed by " + this->getName());   
				break;
			}
			if (it == _formToValidate.end())
			{
				LOG_WARNING("Headmaster does not have this form in a list. Ignoring request");
				return;
			}
		}
	}
}

void Headmaster::execute(Form* p_form)
{
	if (p_form->getSignStatus())
		p_form->execute(this);
	else
		LOG_WARNING("Headmaster won't execute unapproved form");
}

/*Getters and Setters*/


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

