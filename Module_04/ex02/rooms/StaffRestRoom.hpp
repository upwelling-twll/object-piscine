#ifndef STAFFRESTROOM_HPP
# define STAFFRESTROOM_HPP

# include <iostream>
# include "Room.hpp"

class StaffRestRoom  : public Room
{
private:
    // Add member variables here

public:
	/*Member functions*/

	/*Getters and Setters*/

	/*Constructors*/
    StaffRestRoom();

	/*Destructors*/
    ~StaffRestRoom( void );

	/*Overload operators*/
};

std::ostream& operator<<(std::ostream &output_stream, StaffRestRoom& src);

#endif // STAFFRESTROOM_HPP
