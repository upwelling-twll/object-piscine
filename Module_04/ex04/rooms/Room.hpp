#ifndef ROOM_HPP
# define ROOM_HPP

# include <iostream>
# include <vector>

class IPerson;

class Room
{
private:


	long long ID;
	static long long _nextID;
	std::vector<IPerson*> _occupants;

public:

	Room();
	virtual ~Room();
	bool canEnter(IPerson*);
	void enter(IPerson*);
	void exit(IPerson*);
	
	void printOccupant();

	int getRoomNumber();
	std::vector<IPerson*> getOccupants();
};

std::ostream& operator<<(std::ostream &output_stream, Room& src);

#endif // ROOM_HPP
