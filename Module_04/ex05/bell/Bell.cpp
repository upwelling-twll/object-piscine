#include "Bell.hpp"

/*Member functions*/
bool Bell::findObserver(IPerson* obs)
{
	if (!obs)
		return (false);
	if (!_observers.empty())
		return (false);
    for (std::list<IPerson*>::iterator it = _observers.begin(); it != _observers.end(); ++it)
	{
		if ((*it) == obs)
		{
			return (true);
		}
	}
	return (false);
}

void Bell::notify(Break _break)
{
    for (std::list<IPerson*>::iterator it = _observers.begin(); it != _observers.end(); ++it)
	{
		(*it)->update(_break);
	}
}

void Bell::attach(IPerson* observer)
{
	if (observer && !findObserver(observer))
	{
		LOG_DBUG("Bell: " + observer->getName() + " has attached to bell");
		_observers.push_back(observer);
	}
}
	
void Bell::detach(IPerson* observer)
{
	if (observer && findObserver(observer))
	{
		LOG_DBUG("Bell: " + observer->getName() + " has detached from bell");
		_observers.remove(observer);
	}
}

void Bell::doEvent(Event _eventType)
{
	if (_eventType == Event::RingBell)
	{
		if (_breakTime == true)
		{
			_message = "Brake is over. Comeback to classes";
			LOG_INFO(_message);
			notify(Break::BreakEnded);
			_breakTime = false;
		}
		else
		{
			_message = "Time to take a break. Leave classes";
			LOG_INFO(_message);
			notify(Break::BreakStarted);
			_breakTime = true;
		}
	}
	if (_eventType == Event::LunchTime)
	{
		if (_breakTime == true)
		{
			_message = "Lunch is over. Comeback to classes";
			LOG_INFO(_message);
			notify(Break::BreakEnded);
			_breakTime = false;
		}
		else
		{
			_message = "Time to have a lunch. Leave classes";
			LOG_INFO(_message);
			notify(Break::BreakStarted);
			_breakTime = true;
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
Bell::Bell() : _breakTime(false)
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


