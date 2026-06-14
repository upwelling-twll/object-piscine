#include "NeedMoreClassRoomForm.hpp"

/*Member functions*/
void NeedMoreClassRoomForm::method()
{
    // Method implementation
}

/*Getters and Setters*/

/*Constructors*/
NeedMoreClassRoomForm::NeedMoreClassRoomForm(/*Parameterized Constructor*/)
{
   std::cout << "NeedMoreClassRoomForm parameterized constructor is called" << std::endl;
}

NeedMoreClassRoomForm::NeedMoreClassRoomForm()
{
    std::cout << "NeedMoreClassRoomForm default constructor is called" << std::endl;
}

/*Destructors*/
NeedMoreClassRoomForm::~NeedMoreClassRoomForm( void )
{
    std::cout << "NeedMoreClassRoomForm destructor is called" << std::endl;
}

/*Overload operators*/
NeedMoreClassRoomForm& NeedMoreClassRoomForm::operator=(const NeedMoreClassRoomForm& src)
{
	std::cout << "NeedMoreClassRoomForm copy assignment is called" << std::endl;
	if (this != &src)
	{
		// Assinment variables
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& output_stream, NeedMoreClassRoomForm& src)
{
	output_stream << "* NeedMoreClassRoomForm Class info*" << std::endl;
	return output_stream;
}

