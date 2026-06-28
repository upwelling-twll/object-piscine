#include "Courtyard.hpp"
#include "../Debug.hpp"

/*Member functions*/

/*Getters and Setters*/

/*Constructors*/
Courtyard::Courtyard()
{
	LOG_CTOR("Courtyard parameterized constructor is called");
}

/*Destructors*/
Courtyard::~Courtyard( void )
{
	LOG_DTOR("Courtyard destructor is called");
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, Courtyard& src)
{
	output_stream << "* Courtyard Class info*" << std::endl;
	output_stream << static_cast<Room&>(src) << std::endl;
	return output_stream;
}

