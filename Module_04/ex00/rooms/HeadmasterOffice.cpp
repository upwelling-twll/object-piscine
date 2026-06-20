#include "HeadmasterOffice.hpp"

/*Member functions*/

/*Getters and Setters*/

/*Constructors*/
HeadmasterOffice::HeadmasterOffice(int ID) : Room(ID)
{
   std::cout << "HeadmasterOffice parameterized constructor is called" << std::endl;
}


/*Destructors*/
HeadmasterOffice::~HeadmasterOffice( void )
{
    std::cout << "HeadmasterOffice destructor is called" << std::endl;
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, HeadmasterOffice& src)
{
	output_stream << "* HeadmasterOffice Class info*" << std::endl;
	return output_stream;
}

