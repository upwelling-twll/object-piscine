#include "Courtyard.hpp"

/*Member functions*/

/*Getters and Setters*/

/*Constructors*/
Courtyard::Courtyard(int ID) : Room(ID)
{
   std::cout << "Courtyard parameterized constructor is called" << std::endl;
}

/*Destructors*/
Courtyard::~Courtyard( void )
{
    std::cout << "Courtyard destructor is called" << std::endl;
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, Courtyard& src)
{
	output_stream << "* Courtyard Class info*" << std::endl;
	output_stream << Room::src << std::endl;
	return output_stream;
}

