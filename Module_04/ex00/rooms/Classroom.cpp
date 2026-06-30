#include "Classroom.hpp"
#include "../courses/Course.hpp"

/*Member functions*/
void Classroom::assignCourse(Course* p_course)
{
	if (!p_course)
		throw (std::invalid_argument("Classromm: null course can not be assigned"));
    if (!_currentCourse)
		_currentCourse = p_course;
	else
		std::cout << "Classroom: this room is already used for other course" << std::endl;
}

/*Getters and Setters*/
Course* Classroom::getAssignedCourse()
{
	return (_currentCourse);
}

/*Constructors*/
Classroom::Classroom(int id) : Room(id)
{
    std::cout << "Classroom default constructor is called" << std::endl;
}

/*Destructors*/
Classroom::~Classroom( void )
{
    std::cout << "Classroom destructor is called" << std::endl;
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

