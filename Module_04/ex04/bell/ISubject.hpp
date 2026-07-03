#ifndef ISUBJECT_HPP
# define ISUBJECT_HPP

# include <iostream>
# include <string>
# include "../Events.hpp"
#include "../Debug.hpp"


class IPerson;

class ISubject
{
private:
    // Add member variables here

public:
	/*Member functions*/
    virtual void notify(Break _break) = 0;
	virtual void attach(IPerson *observer) = 0;
	virtual void detach(IPerson *observer) = 0;


	/*Getters and Setters*/

	/*Constructors*/

	/*Destructors*/
    virtual ~ISubject( void ) {};

	/*Overload operators*/
};

#endif // ISUBJECT_HPP
