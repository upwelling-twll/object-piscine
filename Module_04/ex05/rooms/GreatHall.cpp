#include "GreatHall.hpp"
#include "../Debug.hpp"

/*Member functions*/

/*Getters and Setters*/

/*Constructors*/
GreatHall::GreatHall()
{
	LOG_CTOR("GreatHall parameterized constructor is called");
}

/*Destructors*/
GreatHall::~GreatHall( void )
{
	LOG_DTOR("GreatHall destructor is called");
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, GreatHall& src)
{
	output_stream << "* GreatHall Class info*" << std::endl;
	output_stream << static_cast<Room&>(src) << std::endl;
	return output_stream;
}

