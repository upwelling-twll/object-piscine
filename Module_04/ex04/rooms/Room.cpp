#include "Room.hpp"
#include "../people/IPerson.hpp"
#include "../Debug.hpp"

long long Room::_nextID = 0;
/*Member functions*/
bool Room::canEnter(IPerson* IPerson)
{
	if (!IPerson)
		throw (std::invalid_argument("Room: null persom can not enter"));
	Room* currentRoom;
	currentRoom = IPerson->getCurrentRoom();
	if (currentRoom == NULL)
		return (true);
	if (currentRoom == this)
		return (false);
	return (false);
}

void Room::enter(IPerson* IPerson)
{
	if (!IPerson)
		throw (std::invalid_argument("Room: null persom can not enter"));
	if (canEnter(IPerson))
	{
		_occupants.push_back(IPerson);
	}
}

void Room::exit(IPerson* IPerson)
{
	if (!IPerson)
		throw (std::invalid_argument("Room: null persom can not enter"));
	if (IPerson->getCurrentRoom() == this)
	{
		for (std::vector<IPerson*>::iterator it = _occupants.begin(); it != _occupants.end(); ++it)
		{
			if (*it == IPerson)
			{
				_occupants.erase(it);
				break;
			}
		}
	}
}

/*Getters and Setters*/
int Room::getRoomNumber()
{
	return (ID);
}

std::vector<IPerson*> Room::getOccupants()
{
	// if (! _occupants)
	// 	return (NULL);
	// else
	return (_occupants);
}

/*Constructors*/
Room::Room()
{
	ID = _nextID;
	Room::_nextID++;
	LOG_CTOR("Room parameterized constructor is called");
}

/*Destructors*/
Room::~Room( void )
{
	LOG_DTOR("Room destructor is called");
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, Room& src)
{
	output_stream << "* Room Class info*" << std::endl;
	output_stream << "ID : " << src.getRoomNumber() << std::endl;
	std::vector<IPerson*> oc = src.getOccupants();
	// if (oc == NULL)
	// 	output_stream << "Occupants : " << 0 << std::endl;
	output_stream << "Occupants : " << oc.size() << std::endl;
	return output_stream;
}

