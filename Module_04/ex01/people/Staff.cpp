#include "Staff.hpp"
#include "../Debug.hpp"

/*Member functions*/
// void Staff::sign(Form* p_form)
// {
    
// }

/*Getters and Setters*/

/*Constructors*/
Staff::Staff(std::string name) : Person(name)
{
	LOG_CTOR("Staff parameterized constructor is called");
}

/*Destructors*/
Staff::~Staff( void )
{
	LOG_DTOR("Staff destructor is called");
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, Staff& src)
{
	output_stream << "* Staff Class info*" << std::endl;
	output_stream << "Name: " << src.getName() << std::endl;
	Room* currentRoom;
	currentRoom = src.getCurrentRoom();
	if (currentRoom == NULL)
		output_stream << "Current Room: null" << std::endl;
	else
		output_stream << "Current Room: " << currentRoom->getRoomNumber() << std::endl;
    return output_stream;
}

