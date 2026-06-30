#include "Classroom.hpp"
#include "../courses/Course.hpp"
#include "../Debug.hpp"

/*Member functions*/
void Classroom::assignCourse(Course* p_course)
{
	if (!p_course)
		LOG_WARNING("Classromm: null course can not be assigned");
    if (!_currentCourse)
	{
		LOG_ACTION("Classroom #" + std::to_string(this->getRoomNumber()) + " got course " + p_course->getName());
		_currentCourse = p_course;
	}
	else
		LOG_WARNING("Classroom: this room is already used for other course");
}

/*Getters and Setters*/
Course* Classroom::getAssignedCourse()
{
	return (_currentCourse);
}

void	Classroom::setFree()
{
	_currentCourse = NULL;
}


/*Constructors*/
Classroom::Classroom() : _currentCourse(NULL)
{
	LOG_CTOR("Classroom default constructor is called");
}

/*Destructors*/
Classroom::~Classroom( void )
{
	LOG_DTOR("Classroom destructor is called");
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, Classroom& src)
{
	output_stream << "* Classroom Class info*" << std::endl;
	Course* ac;
	ac = src.getAssignedCourse();
	if (!ac)
		output_stream << "Assigned course: null" << std::endl;
	output_stream << "Assigned course: " << ac->getName() << std::endl;
	return output_stream;
}

