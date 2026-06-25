#include "StaffRestRoom.hpp"
#include "../Debug.hpp"

/*Member functions*/

/*Getters and Setters*/

/*Constructors*/
StaffRestRoom::StaffRestRoom(int ID) : Room(ID)
{
	LOG_CTOR("StaffRestRoom parameterized constructor is called");
}

/*Destructors*/
StaffRestRoom::~StaffRestRoom( void )
{
	LOG_DTOR("StaffRestRoom destructor is called");
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, StaffRestRoom& src)
{
	output_stream << "* StaffRestRoom Class info*" << std::endl;
	output_stream << static_cast<Room&>(src) << std::endl;
	return output_stream;
}

