#include "Secretary.hpp"
#include "Staff.hpp"
#include "../forms/Form.hpp"

/*Member functions*/
// Form* Secretary::createForm(FormType p_formType)
// {
//     return (new Form(p_formType));
// }

// void Secretary::archiveForm()
// {

// }

/*Getters and Setters*/

/*Constructors*/
Secretary::Secretary(std::string name) : Staff(name)
{
   std::cout << "Secretary parameterized constructor is called" << std::endl;
}

/*Destructors*/
Secretary::~Secretary( void )
{
    std::cout << "Secretary destructor is called" << std::endl;
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

