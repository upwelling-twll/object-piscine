#ifndef PERSON_HPP
# define PERSON_HPP

#include "../rooms/Room.hpp"

# include <iostream>

class Room;
class Person
{
private:
    std::string _name;
	Room* _currentRoom;

public:

	/*Getters and Setters*/
	Room* getCurrentRoom();
	std::string getName();

	/*Constructors*/
	Person(std::string name);

	/*Destructors*/
    ~Person( void );
};

// std::ostream& operator<<(std::ostream &output_stream, Person& src);

#endif // PERSON_HPP
