#ifndef BELL_HPP
# define BELL_HPP

# include <iostream>
# include "ISubject.hpp"
# include "../Event.hpp"
# include "../people/IPerson.hpp"

class Bell : ISubject
{
private:
    std::list<IPerson*> _observers;
	std::string 		_message;
	bool				_breakTime;
	
	
	public:
	/*Member functions*/
    void notify(Event _eventType);
	void attach(IPerson* observer);
	void detach(IPerson* observer);
	bool obeserver(IPerson* obs);
	
	// void doEvent(Event _eventType);

	void createMessage(std::string message);
	void displayObserversNumber();
	/*Getters and Setters*/
	

	/*Constructors*/
	Bell(void);

	/*Destructors*/
    ~Bell( void );

	/*Overload operators*/
};

#endif // BELL_HPP
