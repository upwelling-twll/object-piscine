#include "Staff.hpp"
#include "../Debug.hpp"
#include "../singletonTypedefs.hpp"

/*Member functions*/
Room* Staff::findRecreationSpace()
{
	int size = RoomList::getSingleList().getSize();
	for (int i = 0; i != size; ++i)
	{
		Room* r = RoomList::getSingleList().get(i);
		if (typeid(*r) == typeid(StaffRestRoom))
		{
			StaffRestRoom* srr = dynamic_cast<StaffRestRoom*>(r);
				return (srr);
		}
	}
	return (NULL);
}

void Staff::freeCurrentRoom()
{
	_currentRoom->exit(this);
}


void Staff::update(Break _break)
{
	LOG_DBUG(this->getName() + " received the bell signal");
    switch (_break)
    {
        case Break::BreakStarted:
		{
			_previousRoom = _currentRoom;
			if (_currentRoom != NULL)
				freeCurrentRoom();
			Room* r = findRecreationSpace();
			if (!r)
				_currentRoom = NULL;
			else
			{
				r->enter(this);
				_currentRoom = r;
			}
            break;
		}
        case Break::BreakEnded:
		{
			if (_currentRoom != NULL)
				_currentRoom->exit(this);
			_currentRoom = NULL;
			break;
		}
		case Break::LunchStarted:
		{
			_previousRoom = _currentRoom;
			if (_currentRoom != NULL)
				_currentRoom->exit(this);
			Room* r = findDinningRoom();
			if (!r)
				_currentRoom = NULL;
			else
			{
				r->enter(this);
				_currentRoom = r;
			}
            break;
		}
        case Break::LunchEnded:
		{
			if (_currentRoom != NULL)
				_currentRoom->exit(this);
			_currentRoom = NULL;
			break;
		}
		case Break::GraduationCeremonyStart:
		{
			LOG_DBUG("Staff: " + this->getName() + " received signal for graduation ceremony start");
			Room* dr = findDinningRoom();
			if (!dr)
			{
				LOG_DBUG("Staff: " + this->getName() + " can not attend graduation ceremony beacuse there is no room");
				break;
			}
			_previousRoom = _currentRoom;
			if (_currentRoom != NULL && _currentRoom != dr)
				_currentRoom->exit(this);
			else
			{
				dr->enter(this);
				_currentRoom = dr;
			}
			LOG_ACTION("Staff: " + this->getName() + " arrived to graduation ceremony");
            break;
		}
		case Break::GraduationCeremonyEnd:
		{
			LOG_DBUG("Staff: " + this->getName() + " received signal for graduation ceremony end");
			Room* dr = findDinningRoom();
			if (!dr)
			{
				break;
			}
			if (_currentRoom != NULL && _currentRoom == dr)
				_currentRoom->exit(this);
			LOG_ACTION("Staff: " + this->getName() + " left graduation ceremony");
			if (_previousRoom)
			{
				_previousRoom->enter(this);
				_currentRoom = _previousRoom;
			}
            break;
		}
    }
}

/*Getters and Setters*/

/*Constructors*/
Staff::Staff(std::string name) : IPerson(name)
{
	LOG_CTOR("Staff parameterized constructor is called");
}

Staff::~Staff()
{}

/*Destructors*/


/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, Staff& src)
{
	output_stream << "* Staff Class info*" << std::endl;
	output_stream << "Name: " << src.getName() << std::endl;
	Room* currentRoom;
	currentRoom = src.getCurrentRoom();
	if (currentRoom == NULL)
		output_stream << "Current Room: null" << std::endl;
	else
		output_stream << "Current Room: " << currentRoom->getRoomNumber() << std::endl;
    return output_stream;
}

