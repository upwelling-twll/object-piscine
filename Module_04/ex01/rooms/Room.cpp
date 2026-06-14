#include "Room.hpp"

/*Member functions*/
void Room::method()
{
    // Method implementation
}

/*Getters and Setters*/

/*Constructors*/
Room::Room(/*Parameterized Constructor*/)
{
   std::cout << "Room parameterized constructor is called" << std::endl;
}

Room::Room()
{
    std::cout << "Room default constructor is called" << std::endl;
}

/*Destructors*/
Room::~Room( void )
{
    std::cout << "Room destructor is called" << std::endl;
}

/*Overload operators*/
Room& Room::operator=(const Room& src)
{
	std::cout << "Room copy assignment is called" << std::endl;
	if (this != &src)
	{
		// Assinment variables
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& output_stream, Room& src)
{
	output_stream << "* Room Class info*" << std::endl;
	return output_stream;
}

