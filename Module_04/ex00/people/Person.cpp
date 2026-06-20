#include "Person.hpp"

/*Getters and Setters*/
Room* Person::getCurrentRoom()
{
	return (_currentRoom);
}

std::string Room:getName()
{
	return (_name);
}
/*Constructors*/
Person::Person(std::string name) : _name(name), _currentRoom(NULL)
{
   std::cout << "Person parameterized constructor is called" << std::endl;
}

/*Destructors*/
Person::~Person( void )
{
    std::cout << "Person destructor is called" << std::endl;
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
	output_stream << "Current Room: " << currentRoom->getID() << std::endl;
	return output_stream;
}

