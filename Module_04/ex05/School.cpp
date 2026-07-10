#include "School.hpp"
#include "singletonTypedefs.hpp"
#

/*Member functions*/
void School::runDayRoutine()
{
	LOG_ACTION("School: " + _schoolName + " is running a day routine");
    launchClasses();
	requestRingBell(Event::RingBell);
	LOG_INFO(*((getStudents())[0]));
	requestRingBell(Event::RingBell);
	launchClasses();
	LOG_INFO(*((getStudents())[0]));
	requestRingBell(Event::LunchTime);
	requestRingBell(Event::LunchTime);
	launchClasses();

}

void School::launchClasses()
{
	LOG_ACTION("School: " + _schoolName + " is launching classes");
	std::vector<Professor*> v_profs = getProfessors();
	std::vector<Student*> v_students = getStudents();

	_hm->conductClasses(v_profs, v_students);
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
	_hm = new Headmaster("Albus Dumbledore");
	_sec = new Secretary("Percy Weasley");
    _hm->setSecretary(_sec);
	// students = SingleList<Student>::getSingleList();
    // SingleList<Course>& courses = SingleList<Course>::getSingleList();
    // SingleList<Staff>& staff = SingleList<Staff>::getSingleList();
    // SingleList<Professor>& professors = SingleList<Professor>::getSingleList();
    // SingleList<Room>& rooms = SingleList<Room>::getSingleList();
	

    HeadmasterOffice* hmoffice = new HeadmasterOffice();
    SecretarialOffice* soffice = new SecretarialOffice();
	GreatHall* greatHall = new GreatHall();
	Courtyard* cortyard = new Courtyard();
	StaffRestRoom* staffRR = new StaffRestRoom();
	RoomList::getSingleList().add(hmoffice); //0
	RoomList::getSingleList().add(soffice); //1 
	RoomList::getSingleList().add(greatHall); //2
	RoomList::getSingleList().add(cortyard); //3
	RoomList::getSingleList().add(staffRR); //4

	std::cout << "School parameterized constructor is called" << std::endl;
}

/*Destructors*/
School::~School( void )
{
	delete _hm;
	delete _sec;
    std::cout << "School destructor is called" << std::endl;
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


