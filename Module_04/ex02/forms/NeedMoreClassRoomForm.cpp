#include "NeedMoreClassRoomForm.hpp"
#include "../Debug.hpp"

/*Member functions*/
void NeedMoreClassRoomForm::execute()
{
    // Method implementation
}

/*Getters and Setters*/

/*Constructors*/
NeedMoreClassRoomForm::NeedMoreClassRoomForm(FormType type) : Form(type)
{
    LOG_CTOR("NeedMoreClassRoomForm parameterized constructor is called");
}

/*Destructors*/
NeedMoreClassRoomForm::~NeedMoreClassRoomForm( void )
{
     LOG_DTOR("NeedMoreClassRoomForm destructor is called");
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, NeedMoreClassRoomForm& src)
{
	output_stream << "* NeedMoreClassRoomForm Class info*" << std::endl;
	output_stream << " Sign status: " << src.getSignStatus() << std::endl;
	output_stream << " Execution status: " << src.getExecStatus() << std::endl;
    return output_stream;
}

