#include "Bell.hpp"
#include "../people/people.hpp"

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
	if (_break == Break::GraduationCeremonyStart)
	{
		//order of notification: students->prof+sec->hm
		std::vector<Student*> students = getObserversByType<Student>();
		for (std::vector<Student*>::iterator it = students.begin(); it != students.end(); ++it)
		{
			(*it)->update(_break);
		}
		std::vector<Staff*> staff = getObserversByType<Staff>();
		for (std::vector<Staff*>::iterator it2 = staff.begin() + 1; it2 != staff.end(); ++it2)
		{
			(*it2)->update(_break);
		}
		staff[0]->update(_break); //HM must arrive the last
	}
	else if (_break == Break::GraduationCeremonyEnd)
	{
		//order of notification: students->staff
		std::vector<Student*> students = getObserversByType<Student>();
		for (std::vector<Student*>::iterator it = students.begin(); it != students.end(); ++it)
		{
			(*it)->update(_break);
		}
		std::vector<Staff*> staff = getObserversByType<Staff>();
		for (std::vector<Staff*>::iterator it2 = staff.begin(); it2 != staff.end(); ++it2)
		{
			(*it2)->update(_break);
		}
	}
	//order of notification: any order
	else
	{
		for (std::list<IPerson*>::iterator it = _observers.begin(); it != _observers.end(); ++it)
		{
			(*it)->update(_break);
		}
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
	else if (_eventType == Event::LunchTime)
	{
		if (_breakTime == true)
		{
			_message = "Lunch is over. Comeback to classes";
			LOG_INFO(_message);
			notify(Break::LunchEnded);
			_breakTime = false;
		}
		else
		{
			_message = "Time to have a lunch. Leave classes";
			LOG_INFO(_message);
			notify(Break::LunchStarted);
			_breakTime = true;
		}
	}
	else if (_eventType == Event::GraduationCeremony)
	{
		if (_breakTime == true && _gradCeremony == false)
		{
			_gradCeremony = true;
			_message = "Time to say goodbye to the max level students!";
			LOG_INFO(_message);
			notify(Break::GraduationCeremonyStart);
		}
		else if (_breakTime == false)
		{
			LOG_WARNING("Graduation ceremony can not start when students do classes. Try nex time");
		}
		else
		{
			_message = "Graduation ceremony finished. Comback to your previous rooms.";
			LOG_INFO(_message);
			notify(Break::GraduationCeremonyEnd);
			_gradCeremony = false;
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
Bell::Bell() : _breakTime(false), _gradCeremony(false)
{
    LOG_CTOR("Bell constructor is called");
	_message = "Hello it is Bell"; 
}

/*Destructors*/
Bell::~Bell( void )
{
    LOG_DTOR("Bell destructor is called");
}

/*Overload operators*/


