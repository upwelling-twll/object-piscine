#include "Professor.hpp"

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

void Professor::doClass()
{
	if (_currentCourse)
	{
		LOG_ACTION("Professor " + this->getName() + "  is teaching "+ _currentCourse->getName());
		
		// _currentCourse.doCourseClass();
	}
	else
		LOG_INFO("Professor " + this->getName() + " : no course to do");
}

void Professor::closeCourse()
{
	if (! _currentCourse)
		LOG_INFO("Professor : no course to close");
	else
		// _currentCourse.closeCourse();
		LOG_ACTION("Professor : closed course");
}

/*Getters and Setters*/

/*Constructors*/
Professor::Professor(std::string name) : Staff(name)
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
  
	return output_stream;
}

