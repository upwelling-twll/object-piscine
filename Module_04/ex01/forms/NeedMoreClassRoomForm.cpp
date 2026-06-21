#include "NeedMoreClassRoomForm.hpp"

/*Member functions*/
void NeedMoreClassRoomForm::execute()
{
    // Method implementation
}

/*Getters and Setters*/

/*Constructors*/
NeedMoreClassRoomForm::NeedMoreClassRoomForm(FormType type) : Form(type)
{
   std::cout << "NeedMoreClassRoomForm parameterized constructor is called" << std::endl;
}

/*Destructors*/
NeedMoreClassRoomForm::~NeedMoreClassRoomForm( void )
{
    std::cout << "NeedMoreClassRoomForm destructor is called" << std::endl;
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, NeedMoreClassRoomForm& src)
{
	output_stream << "* NeedMoreClassRoomForm Class info*" << std::endl;
	return output_stream;
}

