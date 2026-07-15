#include "School.hpp"
#include "singletonTypedefs.hpp"


/*Member functions*/
void School::runDayRoutine()
{
	LOG_ACTION("School: " + _schoolName + " is running a day routine");
    launchClasses();
	LOG_DBUG("School: runDayRoutine finished");
	requestRingBell(Event::RingBell);
	// // LOG_INFO(*((getStudents())[0]));
	requestRingBell(Event::RingBell);
	launchClasses();
	// // LOG_INFO(*((getStudents())[0]));
	requestRingBell(Event::LunchTime);
	requestRingBell(Event::LunchTime);
	launchClasses();

}

void School::launchClasses()
{
	LOG_ACTION("School: " + _schoolName + " is launching classes");
	std::vector<Professor*> v_profs = getProfessors();
	std::vector<Student*> v_students = getStudents();
	if (v_profs.empty())
	{
		LOG_WARNING("School: cannot launch classes with 0 professors");
		return;
	}
	if (v_students.empty())
	{
		LOG_WARNING("School: cannot launch classes with 0 students");
		return;
	}
	else
		_hm->conductClasses(v_profs, v_students);
	LOG_DBUG("School: launchClasses finished");
}

void School::requestRingBell(Event eventType)
{
	_hm->ringBell(&_bell, eventType);
}

void School::recruteProfessor(Professor* p)
{
	if (!p)
		throw(std::invalid_argument("School: null professor can not be recruted"));
	else
	{
		LOG_ACTION("School: " + _schoolName + " recruted professor " + p->getName());
		_bell.attach(p);
		p->setHeadmaster(this->_hm);
		ProfessorList::getSingleList().add(p);
		StaffList::getSingleList().add(p);
	}
}

void School::recruteStudent(Student* s)
{
	if (!s)
		throw(std::invalid_argument("School: null student can not be recruted"));
	else
	{
		LOG_ACTION("School: " + _schoolName + " recruted student " + s->getName());
		_bell.attach(s);
		StudentList::getSingleList().add(s);
	}
}

void School::graduationCeremony()
{
	// requestRingBell(GraduationTime);
}

/*Getters and Setters*/

Secretary* School::getSecretary()
{
	return (_sec);
}

Headmaster*	School::getHeadmaster()
{
	return (_hm);
}

Course*	School::getCourse(std::string p_name)
{
	SingleList<Course>& allCourses = SingleList<Course>::getSingleList();
	int size = allCourses.getSize();
	for (int i = 0; i != size; ++i)
	{
		if (allCourses.get(i)->getName() == p_name)
			return (allCourses.get(i));
	}
	return (NULL);
}

std::vector<Student*>	School::getStudents()
{
	return (SingleList<Student>::getSingleList().getVector());
}

std::vector<Professor*>	School::getProfessors()
{
	return (SingleList<Professor>::getSingleList().getVector());
}

std::vector<Course*>	School::getCourses()
{
	return (SingleList<Course>::getSingleList().getVector());
}

/*Constructors*/
School::School(std::string name) : _schoolName(name)
{
	LOG_CTOR("School constructor is called");
	_hm = new Headmaster("Albus Dumbledore");
	_sec = new Secretary("Percy Weasley");
    _hm->setSecretary(_sec);
	_bell.attach(_hm);
	_bell.attach(_sec);

    HeadmasterOffice* hmoffice = new HeadmasterOffice();
    SecretarialOffice* soffice = new SecretarialOffice();
	GreatHall* greatHall = new GreatHall();
	Courtyard* cortyard = new Courtyard();
	StaffRestRoom* staffRR = new StaffRestRoom();
	Classroom* cl = new Classroom();
	RoomList::getSingleList().add(hmoffice); //0
	RoomList::getSingleList().add(soffice); //1 
	RoomList::getSingleList().add(greatHall); //2
	RoomList::getSingleList().add(cortyard); //3
	RoomList::getSingleList().add(staffRR); //4
	RoomList::getSingleList().add(cl); //4

}

/*Destructors*/
School::~School( void )
{
    LOG_DTOR("School destructor is called");
	delete _hm;
	delete _sec;

	int rsize = RoomList::getSingleList().getSize();
	for (int i = 0; i != rsize; i++)
	{
		Room* r = RoomList::getSingleList().get(0);
		RoomList::getSingleList().remove(r);
		// LOG_DBUG("DELETE: ");
		// LOG_DBUG((r));

		delete r;
	}
	int csize = CourseList::getSingleList().getSize();
	for (int i = 0; i != csize; i++)
	{
		Course* c = CourseList::getSingleList().get(0);
		CourseList::getSingleList().remove(c);
		// LOG_DBUG("DELETE: ");
		// LOG_DBUG((r));

		delete c;
	}
}

/*Overload operators*/
School& School::operator=(const School& src)
{
	std::cout << "School copy assignment is called" << std::endl;
	if (this != &src)
	{
		// Assinment variables
	}
	return (*this);
}


