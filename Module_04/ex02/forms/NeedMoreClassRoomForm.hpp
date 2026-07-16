#ifndef NEEDMORECLASSROOMFORM_HPP
# define NEEDMORECLASSROOMFORM_HPP

# include <iostream>
# include "Form.hpp"

class NeedMoreClassRoomForm : public Form
{
private:
    // Add member variables here

public:
	/*Member functions*/
    void execute(Headmaster *hm);
	bool isComplete();

	/*Getters and Setters*/

	/*Constructors*/
    NeedMoreClassRoomForm(FormType type, time_t expirationDate);

	/*Destructors*/
    ~NeedMoreClassRoomForm( void );

	/*Overload operators*/
};

std::ostream& operator<<(std::ostream &output_stream, NeedMoreClassRoomForm& src);

#endif // NEEDMORECLASSROOMFORM_HPP
