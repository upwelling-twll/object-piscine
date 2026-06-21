#include "Student.hpp"

/*Member functions*/
void Student::method()
{
    // Method implementation
}

/*Getters and Setters*/

/*Constructors*/
Student::Student(std::string name) : Person(name)
{
   std::cout << "Student parameterized constructor is called" << std::endl;
}

/*Destructors*/
Student::~Student( void )
{
    std::cout << "Student destructor is called" << std::endl;
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, Student& src)
{
	output_stream << "* Student Class info*" << std::endl;
    output_stream << "Name: " << src.getName() << std::endl;
	Room* currentRoom;
	currentRoom = src.getCurrentRoom();
	if (currentRoom == NULL)
		output_stream << "Current Room: null" << std::endl;
	output_stream << "Current Room: " << currentRoom->getID() << std::endl;
	return output_stream;
}

