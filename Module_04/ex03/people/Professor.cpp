#include "Professor.hpp"
#include "Headmaster.hpp"
#include "Student.hpp"
#include "../singletons.hpp"
#include "../forms/forms.hpp"
#include "../rooms/Room.hpp"




/*Member functions*/
void Professor::assignCourse(Course* p_course)
{
	if (!p_course)
		throw(std::invalid_argument("Professor: null course can not be assigned."));
	if (p_course == _currentCourse)
	{
		std::cout << "Professor : this course is already assigned to this proffessor" << std::endl;
		return;
	}
	_currentCourse = p_course;
}

Classroom*	Professor::findFreeClassroom()
{
	LOG_DBUG("Professor: findFreeClassroom()");
	int size = RoomList::getSingleList().getSize();
	LOG_DBUG("Professor: rooms list size = " + std::to_string(size));	
	for (int i = 0; i != size; ++i)
	{
		Room* r = RoomList::getSingleList().get(i);
		if (typeid(*r) == typeid(Classroom))
		{
			Classroom* cr = dynamic_cast<Classroom*>(r);
			if (cr->getAssignedCourse() == NULL)
			{
				LOG_DBUG("Professor: found free room #" + std::to_string(cr->getRoomNumber()));
				return (cr);
			}
		}
	}
	return (NULL);
}

void Professor::doClass()
{
	if (!_currentCourse)
	{
		LOG_INFO("Professor " + this->getName() + " : does not have a course to do");
		NeedCourseCreationForm* f = _hm->needCourse();
		if (f)
		{
			//TODO: list of random unique course names
			f->setCourseName("Dancing");
			f->setClassesToGraduate(10);
			f->setNumberOfStudents(20);
			f->setResponsable(this);
			_hm->receiveForm(f);
		}
		else
			return;
	}
	if (! _currentCourse->getClassroom())
	{
		LOG_DBUG("Professor " + this->getName() + " has " + _currentCourse->getName() +  " course but no room to do class");
		Classroom* cr = findFreeClassroom();
		if (! cr)
		{
			// *** if no free room found, request new room creation through Headmaster ***
			LOG_DBUG("Professor " + this->getName() + " did not find free room for  " + _currentCourse->getName() + ". Requesting to HM");
			NeedMoreClassRoomForm* f = _hm->needRoom();
			_hm->receiveForm(f);
			cr = findFreeClassroom();
			if (! cr)
			{
				LOG_WARNING("Professor doClass() failed to find free room after requesting the form");
				return;
			}
		}
		_currentCourse->setClassroom(cr);
		cr->assignCourse(_currentCourse);
	}
	LOG_ACTION("Professor " + this->getName() + "  is ready for teaching "+ _currentCourse->getName());
	_currentCourse->holdClass();

	// *** after finishing course we must reset course & class to default state ***
	(_currentCourse->getClassroom())->setFree();
	_currentCourse->setClassroom(NULL);
}

void Professor::closeCourse()
{
	if (! _currentCourse)
		LOG_INFO("Professor : no course to close");
	else
		// _currentCourse.closeCourse();
		LOG_ACTION("Professor : closed course");
}

void Professor::studentHadEnoughClasses(Student* p_student, Course* p_course)
{
	if (! p_course || !p_student)
	{
		LOG_WARNING("Professor: received null argument(s)");
		return;
	}
	if (p_course != _currentCourse)
	{
		LOG_WARNING("Professor: " + this->getName() + " is not responsable for this course "
			 + p_course->getName() + " to graduate " + p_student->getName());
		return ;
	}
	if (!p_student->findCourse(p_course))
	{
		LOG_WARNING("Professor " + this->getName() + " : student "
				 + p_student->getName() + " was not subscribed for " + p_course ->getName() + ", unable to graduate");
		return ;
	}
	if (!_hm)
	{
		LOG_WARNING("Professor " + this->getName() + " : has no headmaster, unable to graduate");
		return ;
	}
	else
	{
		LOG_ACTION("Professor " + this->getName() + " : requesting to graduate student "
				 + p_student->getName() + " from " + p_course ->getName());
		
		//_hm->GraduateStudent();
	}
}


/*Getters and Setters*/
void Professor::setHeadmaster(Headmaster* p_hm)
{
	if (! p_hm)
	{
		LOG_WARNING("Professor: " + this->getName() + " received null headmaster");
		return ;
	}
	else 
	{
		_hm = p_hm;
		LOG_DBUG("Professor: " + this->getName() + " received headmaster " + _hm->getName());		
	}
}

Headmaster* Professor::getHeadmaster()
{
	return (_hm);
}

/*Constructors*/
Professor::Professor(std::string name) : Staff(name), _currentCourse(NULL), _hm(NULL)
{
	LOG_CTOR("Professor parameterized constructor is called");
}

/*Destructors*/
Professor::~Professor( void )
{
    LOG_DTOR("Professor destructor is called");
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, Professor& src)
{
	output_stream << "* Professor Class info*" << std::endl;
	output_stream << src.getName() << std::endl;
	Room* currentRoom;
	currentRoom = src.getCurrentRoom();
    if (currentRoom == NULL)
		output_stream << "Current Room: null" << std::endl;
	else
		output_stream << "Current Room: " << currentRoom->getRoomNumber() << std::endl;
	if (src.getHeadmaster() == NULL)
		output_stream << "Headmaster: null" << std::endl;
	else
		output_stream << "Headmaster: " << src.getHeadmaster()->getName() << std::endl;
	return output_stream;
}

