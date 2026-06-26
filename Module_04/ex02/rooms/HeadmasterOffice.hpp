#ifndef HEADMASTEROFFICE_HPP
# define HEADMASTEROFFICE_HPP

# include <iostream>
# include "Room.hpp"
class HeadmasterOffice : public Room
{
private:
    // Add member variables here

public:
	/*Member functions*/

	/*Getters and Setters*/

	/*Constructors*/
    HeadmasterOffice();

	/*Destructors*/
    ~HeadmasterOffice( void );

	/*Overload operators*/
};

std::ostream& operator<<(std::ostream &output_stream, HeadmasterOffice& src);

#endif // HEADMASTEROFFICE_HPP
