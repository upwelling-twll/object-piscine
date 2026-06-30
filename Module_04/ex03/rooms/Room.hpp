#ifndef ROOM_HPP
# define ROOM_HPP

# include <iostream>
# include <vector>

class Person;

class Room
{
private:


	long long ID;
	static long long _nextID;
	std::vector<Person*> _occupants;

public:

	Room();
	virtual ~Room();
	bool canEnter(Person*);
	void enter(Person*);
	void exit(Person*);
	
	void printOccupant();

	int getRoomNumber();
	std::vector<Person*> getOccupants();
};

std::ostream& operator<<(std::ostream &output_stream, Room& src);

#endif // ROOM_HPP
