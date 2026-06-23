#include "Room.hpp"
#include "../people/Person.hpp"
#include "../Debug.hpp"

/*Member functions*/
bool Room::canEnter(Person* person)
{
	if (!person)
		throw (std::invalid_argument("Room: null persom can not enter"));
	Room* currentRoom;
	currentRoom = person->getCurrentRoom();
	if (currentRoom == NULL)
		return (true);
	if (currentRoom == this)
		return (false);
	return (false);
}

void Room::enter(Person* person)
{
	if (!person)
		throw (std::invalid_argument("Room: null persom can not enter"));
	if (canEnter(person))
	{
		_occupants.push_back(person);
	}
}

void Room::exit(Person* person)
{
	if (!person)
		throw (std::invalid_argument("Room: null persom can not enter"));
	if (person->getCurrentRoom() == this)
	{
		for (std::vector<Person*>::iterator it = _occupants.begin(); it != _occupants.end(); ++it)
		{
			if (*it == person)
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

std::vector<Person*> Room::getOccupants()
{
	// if (! _occupants)
	// 	return (NULL);
	// else
	return (_occupants);
}

/*Constructors*/
Room::Room(int id) : 	ID(id)
{
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
	std::vector<Person*> oc = src.getOccupants();
	// if (oc == NULL)
	// 	output_stream << "Occupants : " << 0 << std::endl;
	output_stream << "Occupants : " << oc.size() << std::endl;
	return output_stream;
}

