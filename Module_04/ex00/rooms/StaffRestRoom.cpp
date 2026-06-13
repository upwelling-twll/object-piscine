#include "StaffRestRoom.hpp"

/*Member functions*/
void StaffRestRoom::method()
{
    // Method implementation
}

/*Getters and Setters*/

/*Constructors*/
StaffRestRoom::StaffRestRoom(/*Parameterized Constructor*/)
{
   std::cout << "StaffRestRoom parameterized constructor is called" << std::endl;
}

StaffRestRoom::StaffRestRoom()
{
    std::cout << "StaffRestRoom default constructor is called" << std::endl;
}

/*Destructors*/
StaffRestRoom::~StaffRestRoom( void )
{
    std::cout << "StaffRestRoom destructor is called" << std::endl;
}

/*Overload operators*/
StaffRestRoom& StaffRestRoom::operator=(const StaffRestRoom& src)
{
	std::cout << "StaffRestRoom copy assignment is called" << std::endl;
	if (this != &src)
	{
		// Assinment variables
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& output_stream, StaffRestRoom& src)
{
	output_stream << "* StaffRestRoom Class info*" << std::endl;
	return output_stream;
}

