// #include "Staff.hpp"
#include <typeinfo>
#include "Headmaster.hpp"
#include "Secretary.hpp"
#include "Professor.hpp"
#include "Student.hpp"

#include "../Debug.hpp"
#include "../courses/Course.hpp"
#include "../singletons.hpp"
#include "../FormType.hpp"


void Headmaster::ringBell(Bell* bell, Event eventType)
{
	LOG_ACTION("Headmaster is ringing a bell");
	bell->doEvent(eventType);
}

void Headmaster::update(Break _break)
{
	LOG_DBUG(this->getName() + " received the bell signal");
    switch (_break)
    {
        case Break::BreakStarted:
		{
			_previousRoom = _currentRoom;
			if (_currentRoom != NULL)
				_currentRoom->exit(this);
			_currentRoom = findRecreationSpace();
            break;
		}

        case Break::BreakEnded:
		{
			if (_previousRoom != NULL)
				_previousRoom->enter(this);
			_currentRoom = _previousRoom;
			break;
		}
		case Break::LunchStarted:
		{
			_previousRoom = _currentRoom;
			if (_currentRoom != NULL)
				_currentRoom->exit(this);
			Room* r = findDinningRoom();
			if (!r)
				_currentRoom = NULL;
			else
			{
				r->enter(this);
				_currentRoom = r;
			}
            break;
		}
        case Break::LunchEnded:
		{
			if (_currentRoom != NULL)
				_currentRoom->exit(this);
			_currentRoom = NULL;
			break;
		}
    }
}

/*Member functions*/
void Headmaster::receiveForm(std::unique_ptr<Form> p_form)
{
	if (! p_form)
		throw(std::invalid_argument("Headmaster: null form can not be received."));
	else
	{
		for (std::vector<std::unique_ptr<Form>>::iterator it = _formToValidate.begin(); it != _formToValidate.end(); ++it)
		{
			if (it->get() == p_form.get())
			{
				std::cout << "Headmaster: form is already received." << std::endl;
				return;
			}
		}
		_formToValidate.push_back(std::move(p_form));
	}

	// operate on the last received form
	Form* raw = _formToValidate.back().get();
	sign(raw);
	execute(raw);

	// move to secretary archive
	if (p_secretary)
	{
		auto toArchive = std::move(_formToValidate.back());
		_formToValidate.pop_back();
		p_secretary->archiveForm(std::move(toArchive));
	}
	else
	{
		LOG_WARNING("Headmaster: no secretary to archive the form");
	}

	LOG_DBUG("Headmaster: finished signing and executing form");
}

void Headmaster::sign(Form* p_form)
{
	p_form->beSigned();
	LOG_ACTION("Headmaster " + this->getName() + ": signed form");   
}

void Headmaster::execute(Form* p_form)
{
	if (!p_form)
		std::invalid_argument("Headmaster execute() recevied null form");
	if (p_form->getSignStatus())
	{
		p_form->execute(this);
		// archiving is handled by receiveForm after execution
	}
	else
	{
		LOG_WARNING("Headmaster won't execute anapproved form");
		// keep form for later approval
	}

}

void Headmaster::conductClasses(std::vector<Professor*> professors, std::vector<Student*> students)
{
	LOG_DBUG("Headmaster: professors list size = " + std::to_string(professors.size()));
	LOG_ACTION("Headmaster: gives command to attend classes");
	for (std::vector<Professor*>::iterator it = professors.begin(); it != professors.end(); ++it)
	{
		if (*it)
		{
			LOG_DBUG("Headmaster:found professor who should prepare for class - " + (*it)->getName());
			(*it)->prepareForClass();
		}
	}
	LOG_DBUG("Headmaster: students list size = " + std::to_string(students.size()));
	for (std::vector<Student*>::iterator it = students.begin(); it != students.end(); ++it)
	{
		if (*it)
		{
			LOG_DBUG("Headmaster:found student who should prepare for class - " + (*it)->getName());
			(*it)->prepareForClass(this);
		}
	}
	for (std::vector<Professor*>::iterator it = professors.begin(); it != professors.end(); ++it)
	{
		if (*it)
		{
			LOG_DBUG("Headmaster:found professor who should start class - " + (*it)->getName());
			(*it)->doClass();
		}
	}
	LOG_DBUG("Headmaster: conductClasses finished");
}

//requests from staff & students
std::unique_ptr<NeedCourseCreationForm> Headmaster::needCourse()
{
	if (!p_secretary)
		LOG_WARNING("Headmaster " + this->getName() + " has no secretery. Can not proceed with the request");
	time_t et = time(0) + (3600 * 24); //24 hours from now
	auto base = p_secretary->createForm(FormType::NeedCourseCreation, et);
	if (!base)
		return nullptr;
	NeedCourseCreationForm* raw = dynamic_cast<NeedCourseCreationForm*>(base.get());
	if (!raw)
		return nullptr;
	base.release();
	return std::unique_ptr<NeedCourseCreationForm>(raw);
}

std::unique_ptr<SubscriptionToCourseForm> Headmaster::subscribeToCourse()
{
	if (!p_secretary)
		LOG_WARNING("Headmaster " + this->getName() + " has no secretery. Can not proceed with the request");
	time_t et = time(0) + (3600 * 24); //24 hours from now
	auto base = p_secretary->createForm(FormType::SubscriptionToCourse, et);
	if (!base)
		return nullptr;
	SubscriptionToCourseForm* raw = dynamic_cast<SubscriptionToCourseForm*>(base.get());
	if (!raw)
		return nullptr;
	base.release();
	return std::unique_ptr<SubscriptionToCourseForm>(raw);
}

std::unique_ptr<NeedMoreClassRoomForm> Headmaster::needRoom()
{
	if (!p_secretary)
		LOG_WARNING("Headmaster " + this->getName() + " has no secretery. Can not proceed with the request");
	time_t et = time(0) + (3600 * 24); //24 hours from now
	auto base = p_secretary->createForm(FormType::NeedMoreClassRoom, et);
	if (!base)
		return nullptr;
	NeedMoreClassRoomForm* raw = dynamic_cast<NeedMoreClassRoomForm*>(base.get());
	if (!raw)
		return nullptr;
	base.release();
	return std::unique_ptr<NeedMoreClassRoomForm>(raw);
}

std::unique_ptr<CourseFinishedForm> Headmaster::graduateStudent()
{
	if (!p_secretary)
		LOG_WARNING("Headmaster " + this->getName() + " has no secretery. Can not proceed with the request");
	time_t et = time(0) + (3600 * 24); //24 hours from now
	auto base = p_secretary->createForm(FormType::CourseFinished, et);
	if (!base)
		return nullptr;
	CourseFinishedForm* raw = dynamic_cast<CourseFinishedForm*>(base.get());
	if (!raw)
		return nullptr;
	base.release();
	return std::unique_ptr<CourseFinishedForm>(raw);
}

/*Getters and Setters*/
void Headmaster::setSecretary(Secretary* s)
{
	p_secretary = s;
}


/*Constructors*/
Headmaster::Headmaster(std::string name) : Staff(name), p_secretary(NULL)
{
	LOG_CTOR("Headmaster parameterized constructor is called");
}

/*Destructors*/
Headmaster::~Headmaster( void )
{
	LOG_DTOR("Headmaster destructor is called");
	// unique_ptr in _formToValidate will clean up automatically
	_formToValidate.clear();
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, Headmaster& src)
{
	output_stream << "* Headmaster Class info*" << std::endl;
	output_stream << "Name: " << src.getName() << std::endl;
	Room* currentRoom;
	currentRoom = src.getCurrentRoom();
    if (currentRoom == NULL)
		output_stream << "Current Room: null" << std::endl;
	else
		output_stream << "Current Room: " << currentRoom->getRoomNumber() << std::endl;
  
	return output_stream;
}

