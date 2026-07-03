#include "Room.hpp"
#include "../people/IPerson.hpp"
#include "../Debug.hpp"

long long Room::_nextID = 0;
/*Member functions*/
bool Room::canEnter(IPerson* p)
{
	if (!p)
		throw (std::invalid_argument("Room: null persom can not enter"));
	Room* currentRoom;
	currentRoom = p->getCurrentRoom();
	if (currentRoom == NULL)
		return (true);
	if (currentRoom == this)
		return (false);
	return (false);
}

void Room::enter(IPerson* p)
{
	if (!p)
		throw (std::invalid_argument("Room: null persom can not enter"));
	if (canEnter(p))
	{
		_occupants.push_back(p);
		LOG_ACTION("Room: " + p->getName() + " entered room #" + std::to_string(ID));
	}
}

void Room::exit(IPerson* p)
{
	if (!p)
		throw (std::invalid_argument("Room: null persom can not enter"));
	if (p->getCurrentRoom() == this)
	{
		for (std::vector<IPerson*>::iterator it = _occupants.begin(); it != _occupants.end(); ++it)
		{
			if (*it == p)
			{
				_occupants.erase(it);
				LOG_ACTION("Room: " + p->getName() + " left room #" + std::to_string(ID));
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

