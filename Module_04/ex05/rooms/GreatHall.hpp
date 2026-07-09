#ifndef GreatHall_HPP
# define GreatHall_HPP

# include <iostream>
# include "Room.hpp"

class GreatHall : public Room
{
private:
    // Add member variables here

public:
	/*Member functions*/

	/*Getters and Setters*/

	/*Constructors*/
    GreatHall();

	/*Destructors*/
    ~GreatHall( void );

	/*Overload operators*/
};

std::ostream& operator<<(std::ostream &output_stream, GreatHall& src);


#endif // GreatHall_HPP
