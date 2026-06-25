#include "Staff.hpp"

/*Member functions*/
// void Staff::sign(Form* p_form)
// {
    
// }

/*Getters and Setters*/

/*Constructors*/
Staff::Staff(std::string name) : Person(name)
{
   std::cout << "Staff parameterized constructor is called" << std::endl;
}

/*Destructors*/
Staff::~Staff( void )
{
    std::cout << "Staff destructor is called" << std::endl;
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, Staff& src)
{
	output_stream << "* Staff Class info*" << std::endl;
	return output_stream;
}

