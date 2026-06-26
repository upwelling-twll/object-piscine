#ifndef COURTYARD_HPP
# define COURTYARD_HPP

# include <iostream>
# include "Room.hpp"

class Courtyard : public Room
{
private:
    // Add member variables here

public:
	/*Member functions*/

	/*Getters and Setters*/

	/*Constructors*/
    Courtyard();

	/*Destructors*/
    ~Courtyard( void );

	/*Overload operators*/
};

std::ostream& operator<<(std::ostream &output_stream, Courtyard& src);


#endif // COURTYARD_HPP
