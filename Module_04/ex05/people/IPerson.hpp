#ifndef IPerson_HPP
# define IPerson_HPP

#include "../rooms/Room.hpp"
#include "../Events.hpp"
#include "../FormType.hpp"
#include "../Debug.hpp"

# include <iostream>
# include <list>



class Room;
class GreatHall;
class IPerson
{
protected:
    std::string _name;
	Room* _currentRoom;
	Room* _previousRoom;

public:

	/*Getters and Setters*/
	Room*			getCurrentRoom();
	std::string		getName();
	virtual void 	update(Break _break) = 0;
	virtual Room* findRecreationSpace() = 0;

	Room* findDinningRoom();
	
	/*Constructors*/
	IPerson(std::string name);

	/*Destructors*/
    ~IPerson( void );
};

// std::ostream& operator<<(std::ostream &output_stream, IPerson& src);

#endif // IPerson_HPP
