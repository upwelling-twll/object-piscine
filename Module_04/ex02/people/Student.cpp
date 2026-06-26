#include "Student.hpp"
#include "../Debug.hpp"

/*Member functions*/
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
	LOG_DBUG("Student: " + this->getName() + " subscribed to course " + p_course->getName());
}

/*Getters and Setters*/
const std::vector<Course*> Student::getCourses() const
{
	return (_subscribedCourse);
}

/*Constructors*/
Student::Student(std::string name) : Person(name)
{
	LOG_CTOR("Student parameterized constructor is called");
}

/*Destructors*/
Student::~Student( void )
{
	LOG_DTOR("Student destructor is called");
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

