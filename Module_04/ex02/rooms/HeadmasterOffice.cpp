#include "HeadmasterOffice.hpp"
#include "../Debug.hpp"

/*Member functions*/

/*Getters and Setters*/

/*Constructors*/
HeadmasterOffice::HeadmasterOffice(int ID) : Room(ID)
{
	LOG_CTOR("HeadmasterOffice parameterized constructor is called");
}


/*Destructors*/
HeadmasterOffice::~HeadmasterOffice( void )
{
	LOG_DTOR("HeadmasterOffice destructor is called");
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, HeadmasterOffice& src)
{
	output_stream << "* HeadmasterOffice Class info*" << std::endl;
	output_stream << static_cast<Room&>(src) << std::endl;
	return output_stream;
}

