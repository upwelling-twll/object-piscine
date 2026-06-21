#include "Headmaster.hpp"
#include "Staff.hpp"

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

/*Getters and Setters*/

/*Constructors*/
Headmaster::Headmaster(std::string name) : Staff(name)
{
   std::cout << "Headmaster parameterized constructor is called" << std::endl;
}

/*Destructors*/
Headmaster::~Headmaster( void )
{
    std::cout << "Headmaster destructor is called" << std::endl;
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, Headmaster& src)
{
	output_stream << "* Headmaster Class info*" << std::endl;
	output_stream << "Name: " << src.getName() << std::endl;
	return output_stream;
}

