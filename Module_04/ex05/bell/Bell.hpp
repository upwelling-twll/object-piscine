#ifndef BELL_HPP
# define BELL_HPP

# include <iostream>
# include "ISubject.hpp"
# include "../Events.hpp"
# include "../people/IPerson.hpp"

class Student;

class Bell : public ISubject
{
private:
    std::list<IPerson*> _observers;
	std::string 		_message;
	bool				_breakTime;
	bool				_gradCeremony;
	
	
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
	template <typename T>
	std::vector<T*> getObserversByType()
	{
		std::vector<T*> result;
		for (IPerson* observer : _observers)
		{
			if (T* p = dynamic_cast<T*>(observer))
				result.push_back(p);
		}
		return result;
	}

	/*Constructors*/
	Bell(void);

	/*Destructors*/
    ~Bell( void );

	/*Overload operators*/
};

#endif // BELL_HPP
