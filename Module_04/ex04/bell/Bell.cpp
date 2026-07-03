#include "Bell.hpp"

/*Member functions*/
bool Bell::findObserver(IPerson* obs)
{
	if (!obs)
		return (false);
    for (std::list<IPerson*>::iterator it = _observers.start(); it != _observers.end(); ++it)
	{
		if ((*it) == obs)
		{
			return (true);
		}
	}
	return (false);
}

void Bell::notify()
{
    for (std::list<IPerson*>::iterator it = _observers.start(); it != _observers.end(); ++it)
	{
		(*it)->update(message);
	}
}

void Bell::attach(IPerson* observer)
{
	if (observer && !findObserver(observer))
	{
		_observers.push_back(observer);
	}
}
	
void Bell::detach(IPerson* observer)
{
	if (observer && findObserver(observer))
	{
		_observers.remove(observer);
	}
}

void doEvent(Event _eventType)
{
	if (_eventType == Event::RingBell)
	{
		if (_breakTime)
		{
			_message = "Brake is over. Comeback to classes"
			notify();
		}
		else
		{
			_message = "Time to take a break. Leave classes"
			notify();
		}
	}
}

void Bell::createMessage(std::string message)
{
	this->_message = message;
}

void Bell::displayObserversNumber()
{
	LOG_INFO("Bell subject has " + std::to_string(_observers.size()) + " observers");
}

/*Getters and Setters*/

/*Constructors*/
Bell::Bell() : _breakTime(true)
{
	_message = "Hello it is Bell"; 
    std::cout << "Bell default constructor is called" << std::endl;
}

/*Destructors*/
Bell::~Bell( void )
{
    std::cout << "Bell destructor is called" << std::endl;
}

/*Overload operators*/


