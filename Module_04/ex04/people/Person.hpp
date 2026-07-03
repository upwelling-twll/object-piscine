#ifndef IPerson_HPP
# define IPerson_HPP

#include "../rooms/Room.hpp"
#include "../FormType.hpp"
# include <iostream>

class Room;

class IPerson
{
private:
    std::string _name;
	Room* _currentRoom;

public:

	/*Getters and Setters*/
	Room*			getCurrentRoom();
	std::string		getName();
	void			update(std::string message);

	/*Constructors*/
	IPerson(std::string name);

	/*Destructors*/
    ~IPerson( void );
};

// std::ostream& operator<<(std::ostream &output_stream, IPerson& src);

#endif // IPerson_HPP
