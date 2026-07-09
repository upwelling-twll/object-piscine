#ifndef STAFF_HPP
# define STAFF_HPP

# include <iostream>
# include "IPerson.hpp"


class StaffRestRoom;

class Staff : public IPerson
{
private:
    

public:
	/*Member functions*/
	Room* findRecreationSpace();
	void update(Break _break);

	/*Getters and Setters*/

	/*Constructors*/
    Staff(std::string name);

	// /*Destructors*/
    virtual ~Staff( void );

	// /*Overload operators*/
};

std::ostream& operator<<(std::ostream &output_stream, Staff& src);

#endif // STAFF_HPP
