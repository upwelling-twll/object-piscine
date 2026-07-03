#include "IPerson.hpp"
#include "../Debug.hpp"

/*Observer method*/

/*Getters and Setters*/
Room* IPerson::getCurrentRoom()
{
	return (_currentRoom);
}

std::string IPerson::getName()
{
	return (_name);
}

/*Constructors*/
IPerson::IPerson(std::string name) : _name(name), _currentRoom(NULL), _previousRoom(NULL)
{
	LOG_CTOR("IPerson parameterized constructor is called");
}

/*Destructors*/
IPerson::~IPerson( void )
{
	LOG_DTOR("IPerson destructor is called");
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, IPerson& src)
{
	output_stream << "* IPerson Class info*" << std::endl;
	output_stream << "Name: " << src.getName() << std::endl;
	Room* currentRoom;
	currentRoom = src.getCurrentRoom();
	if (currentRoom == NULL)
		output_stream << "Current Room: null" << std::endl;
	output_stream << "Current Room: " << currentRoom->getRoomNumber() << std::endl;
	return output_stream;
}

