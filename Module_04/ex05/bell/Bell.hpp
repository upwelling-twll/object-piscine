#ifndef BELL_HPP
# define BELL_HPP

# include <iostream>
# include "ISubject.hpp"
# include "../Events.hpp"
# include "../people/IPerson.hpp"

class Bell : public ISubject
{
private:
    std::list<IPerson*> _observers;
	std::string 		_message;
	bool				_breakTime;
	
	
public:
	/*Member functions*/
    void notify(Break _break);
	void attach(IPerson* observer);
	void detach(IPerson* observer);
	bool obeserver(IPerson* obs);
	bool findObserver(IPerson* obs);
	void doEvent(Event _eventType);


	
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
