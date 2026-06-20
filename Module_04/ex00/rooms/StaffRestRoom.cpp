#include "StaffRestRoom.hpp"

/*Member functions*/

/*Getters and Setters*/

/*Constructors*/
StaffRestRoom::StaffRestRoom(int ID) : Room(ID)
{
   std::cout << "StaffRestRoom parameterized constructor is called" << std::endl;
}

/*Destructors*/
StaffRestRoom::~StaffRestRoom( void )
{
    std::cout << "StaffRestRoom destructor is called" << std::endl;
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, StaffRestRoom& src)
{
	output_stream << "* StaffRestRoom Class info*" << std::endl;
	return output_stream;
}

