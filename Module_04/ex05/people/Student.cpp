#include "Student.hpp"
#include "../Debug.hpp"
#include "../singletons.hpp"
#include "../forms/SubscriptionToCourseForm.hpp"
#include "Headmaster.hpp"
#include "../singletonTypedefs.hpp"


/*Member functions*/
Room* Student::findRecreationSpace()
{
	int size = RoomList::getSingleList().getSize();
	for (int i = 0; i != size; ++i)
	{
		Room* r = RoomList::getSingleList().get(i);
		if (typeid(*r) == typeid(Courtyard))
		{
			Courtyard* cr = dynamic_cast<Courtyard*>(r);
				return (cr);
		}
	}
	return (NULL);
}

void Student::update(Break _break)
{
	LOG_DBUG(this->getName() + " received the bell signal");
    switch (_break)
    {
        case Break::BreakStarted:
		{
			_previousRoom = _currentRoom;
			if (_currentRoom != NULL)
				_currentRoom->exit(this);
			Room* r = findRecreationSpace();
			if (!r)
				_currentRoom = NULL;
			else
			{
				r->enter(this);
				_currentRoom = r;
			}
            break;
		}
        case Break::BreakEnded:
		{
			if (_currentRoom != NULL)
				_currentRoom->exit(this);
			_currentRoom = NULL;
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

Course* Student::findUniqueCourse()
{
	int size = CourseList::getSingleList().getSize();
	if (_attendance.empty())
	{
		std::random_device rd;  // Obtain a random seed from the hardware
		std::mt19937 gen(rd()); // Initialize the Mersenne Twister engine with the seed
    	std::uniform_int_distribution<> distr(0, size - 1); // Define the range [min, max]
		
    	int random_num = distr(gen); // Generate the random integer
		LOG_DBUG("Student " + this->getName() + " has 0 attendance. Searching for the 1st random course from list of " + std::to_string(size) + ". Starting from " + std::to_string(random_num));
		for (int i = 0; i != size; ++i)
		{
			Course* c = CourseList::getSingleList().get(random_num);
			if (c->getMaxStudents() > c->getNumberOfStudents()) //TODO : move this check to Headmaster, reject form signing if false
					return (c); //course is unique for this student AND has free spots
			random_num++;
		}
		return (NULL);
	}
	for (int i = 0; i != size; ++i)
	{
		Course* c = CourseList::getSingleList().get(i);
		auto it = _attendance.find(c);
		if (it != _attendance.end())
			continue; //means that course was already attended
		else
		{
			if (c->getMaxStudents() > c->getNumberOfStudents()) //TODO : move this check to Headmaster, reject form signing if false
				return (c); //course is unique for this student AND has free spots
		}
	}
	return (NULL);
}

void	Student::prepareForClass(Headmaster* hm)
{
	LOG_DBUG("Student " + getName() + " is checking subscribed courses");
	if (! _subscribedCourse.empty())
		return;
	else
	{
		LOG_DBUG("Student " + getName() + " will search for new course");
		Course* c = findUniqueCourse();
		if (!c)
		{
			LOG_DBUG("Student " + getName() + " already graduated or subscribed to all possible courses");
			return;
		}
		SubscriptionToCourseForm* f = hm->subscribeToCourse();
		f->setStudent(this);
		f->setCourse(c);
		hm->receiveForm(f);
	}
}

void	Student::addAttendance(Course* p_course)
{
	if (findCourse(p_course))
	{
		auto it = _attendance.find(p_course);
		if (it != _attendance.end())
		{
			it->second ++;
			LOG_DBUG("Student addAttendace(): adding attendance for course");
		}
		else
		{
			_attendance.insert({p_course, 1});
			LOG_DBUG("Student addAttendace(): adding first attendance for course");
		}
	}
}

Course*	Student::findCourse(Course* p_course)
{
	if (! p_course)
	{
		LOG_WARNING("Student: can not find null course");
		return (NULL);
	}
	for (std::vector<Course*>::iterator it = _subscribedCourse.begin(); it != _subscribedCourse.end(); ++it)
	{
		if (*it == p_course)
			return (*it);
	}
	return (NULL);
}

void Student::attendClass(Classroom* p_classroom)
{
	if (!p_classroom)
	{	
		LOG_WARNING("Student " + getName() + " can not attend course with null classroom");
		return;
	}
	else
	{
		Course* c = p_classroom->getAssignedCourse(); 
		if (c && this->findCourse(c))
		{
			Room* r = c->getClassroom();
			if (r)
			{
				r->enter(this);
				_currentRoom = r;
			}
			addAttendance(c);
			return;
		}
	}
	
}

void Student::graduate(Course* p_course)
{
	if (!p_course)
	{
		LOG_WARNING("Student graduate(): can not graduate null course");
		return;
	}
	if (!this->findCourse(p_course))
	{
		LOG_WARNING("Student graduate(): was not subscribed to course");
		return;
	}
	else
	{
		for (std::vector<Course*>::iterator it = _subscribedCourse.begin(); it != _subscribedCourse.end(); ++it)
		{
			if ((*it) == p_course)
			{
				_subscribedCourse.erase(it);
				_level++;
				LOG_DBUG("Student  graduate(): " + getName() + " unsubscribed from " + p_course->getName());
				break;
			}
		}
	}
}


void Student::addCourse(Course* p_course)
{
	if (!p_course)
	{
		LOG_WARNING("Student: can not add null course");
		return;
	}
	else if (findCourse(p_course))
	{
		LOG_WARNING("Student: already subscribed to " + p_course->getName());
		return;
	}
	_subscribedCourse.push_back(p_course);
	LOG_ACTION("Student: " + this->getName() + " subscribed to course " + p_course->getName());
}

/*Getters and Setters*/
const std::vector<Course*> Student::getCourses() const
{
	return (_subscribedCourse);
}

/*Constructors*/
Student::Student(std::string name) : IPerson(name), _level(0)
{
	LOG_CTOR("Student parameterized constructor is called");
}

/*Destructors*/
Student::~Student( void )
{
	LOG_DTOR("Student destructor is called");
}

int	Student::getAttendance(Course* p_course)
{
	auto it = _attendance.find(p_course);
	if (it != _attendance.end())
		return (it->second);
	else
		return (-1);
}


/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, Student& src)
{
	output_stream << "* Student Class info*" << std::endl;
    output_stream << "Name: " << src.getName() << std::endl;
	Room* currentRoom;
	currentRoom = src.getCurrentRoom();
	if (currentRoom == NULL)
		output_stream << "Current Room: null" << std::endl;
	else
		output_stream << "Current Room: " << currentRoom->getRoomNumber() << std::endl;
	const std::vector<Course*> courses = src.getCourses();
	if (courses.size() == 0)
		output_stream << "Subscribed to courses: no courses" << std::endl;
	else
	{
		output_stream << "Subscribed to courses: " << std::endl;
		for (std::vector<Course*>::const_iterator it = courses.begin(); it != courses.end(); ++it)
		{
			output_stream << "	- " << (*it)->getName() << std::endl;
		}
	}
	return output_stream;
}

