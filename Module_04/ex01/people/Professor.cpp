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
		std::cout << "Professor : doing class" << std::endl;
		// _currentCourse.doCourseClass();
	}
	else
		std::cout << "Professor : no course to do" << std::endl;
}

void Professor::closeCourse()
{
	if (! _currentCourse)
		std::cout << "Professor : no course to close" << std::endl;
	else
		// _currentCourse.closeCourse();
		std::cout << "Professor : closed course" << std::endl;
}

/*Getters and Setters*/

/*Constructors*/
Professor::Professor(std::string name) : Staff(name)
{
   std::cout << "Professor parameterized constructor is called" << std::endl;
}

/*Destructors*/
Professor::~Professor( void )
{
    std::cout << "Professor destructor is called" << std::endl;
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, Professor& src)
{
	output_stream << "* Professor Class info*" << std::endl;
	output_stream << src.getName() << std::endl;
	return output_stream;
}

