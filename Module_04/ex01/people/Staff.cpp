#include "Staff.hpp"

/*Member functions*/
// void Staff::sign(Form* p_form)
// {
    
// }

/*Getters and Setters*/

/*Constructors*/
Staff::Staff(std::string name) : Person(name)
{
   std::cout << "Staff parameterized constructor is called" << std::endl;
}

/*Destructors*/
Staff::~Staff( void )
{
    std::cout << "Staff destructor is called" << std::endl;
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

