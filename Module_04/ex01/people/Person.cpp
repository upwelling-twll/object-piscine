#include "Person.hpp"
#include "../Debug.hpp"

/*Getters and Setters*/
Room* Person::getCurrentRoom()
{
	return (_currentRoom);
}

std::string Person::getName()
{
	return (_name);
}
/*Constructors*/
Person::Person(std::string name) : _name(name), _currentRoom(NULL)
{
	LOG_CTOR("Person parameterized constructor is called");
}

/*Destructors*/
Person::~Person( void )
{
	LOG_DTOR("Person destructor is called");
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, Person& src)
{
	output_stream << "* Person Class info*" << std::endl;
	output_stream << "Name: " << src.getName() << std::endl;
	Room* currentRoom;
	currentRoom = src.getCurrentRoom();
	if (currentRoom == NULL)
		output_stream << "Current Room: null" << std::endl;
	output_stream << "Current Room: " << currentRoom->getRoomNumber() << std::endl;
	return output_stream;
}

