#include "IPerson.hpp"
#include "../Debug.hpp"
#include "../singletonTypedefs.hpp"

/*Observer method*/

/*Getters and Setters*/
Room* IPerson::findDinningRoom()
{
	int size = RoomList::getSingleList().getSize();
	LOG_DBUG("IPerson: searching for dinning room in a list of " + std::to_string(size));
	for (int i = 0; i != size; ++i)
	{
		Room* r = RoomList::getSingleList().get(i);
		if (typeid(*r) == typeid(GreatHall))
		{
			GreatHall* dr = dynamic_cast<GreatHall*>(r);
			{
				LOG_DBUG("IPerson: found dinning room #" + std::to_string(r->getRoomNumber()));
				return (dr);
			}
			LOG_DBUG("IPerson: found dinning room #" + std::to_string(r->getRoomNumber()) + " but could not cast");
		}
	}
	return (NULL);
}

Room* IPerson::getCurrentRoom()
{
	return (_currentRoom);
}

void	IPerson::setCurrentRoom(Room* p_room)
{
	_currentRoom = p_room;
}


std::string IPerson::getName()
{
	return (_name);
}

/*Constructors*/
IPerson::IPerson(std::string name) : _name(name), _currentRoom(NULL), _previousRoom(NULL)
{
	LOG_CTOR("IPerson parameterized constructor is called");
}

/*Destructors*/
IPerson::~IPerson( void )
{
	LOG_DTOR("IPerson destructor is called");
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, IPerson& src)
{
	output_stream << "* IPerson Class info*" << std::endl;
	output_stream << "Name: " << src.getName() << std::endl;
	Room* currentRoom;
	currentRoom = src.getCurrentRoom();
	if (currentRoom == NULL)
		output_stream << "Current Room: null" << std::endl;
	output_stream << "Current Room: " << currentRoom->getRoomNumber() << std::endl;
	return output_stream;
}

