#ifndef ROOM_HPP
# define ROOM_HPP

# include <iostream>

class Room
{
private:

	long long ID;
	std::vector<Person*> _occupants;

public:

	Room();
	bool canEnter(Person*);
	void enter(Person*);
	void exit(Person*);
	
	void printOccupant();
};

std::ostream& operator<<(std::ostream &output_stream, Room& src);

#endif // ROOM_HPP
