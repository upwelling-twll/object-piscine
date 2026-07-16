#include "NeedMoreClassRoomForm.hpp"
#include "../Debug.hpp"
#include "../rooms/Classroom.hpp"
#include "../singletons.hpp"

/*Member functions*/
void NeedMoreClassRoomForm::execute(Headmaster *hm)
{
    if (!hm)
        return;
    LOG_ACTION("NeedMoreClassRoomForm: executed by headmaster " + hm->getName());
    Classroom* newRoom = new Classroom();
    if (newRoom)
    {
        RoomList::getSingleList().add(newRoom);
		this->_execStatus = true;
        LOG_ACTION("NeedMoreClassRoomForm: created room with ID " + std::to_string(newRoom->getRoomNumber()));
    }
    else 
        LOG_WARNING("NeedMoreClassRoomForm:room was not created");
}

bool NeedMoreClassRoomForm::isComplete()
{
    return (true);
}

/*Getters and Setters*/

/*Constructors*/
NeedMoreClassRoomForm::NeedMoreClassRoomForm(FormType type, time_t expirationDate) : Form(type, expirationDate)
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

