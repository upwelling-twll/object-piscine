#include "School.hpp"

/*Member functions*/
void School::runDayRoutine()
{
    // Method implementation
}

/*Getters and Setters*/

/*Constructors*/
School::School(std::string name) : _schoolName(name)
{
	Headmaster* _hm = new Headmaster("Albus Dumbledore");
	SingleList<Student>& students = SingleList<Student>::getSingleList();
    SingleList<Course>& courses = SingleList<Course>::getSingleList();
    SingleList<Staff>& staff = SingleList<Staff>::getSingleList();
    SingleList<Room>& rooms = SingleList<Room>::getSingleList();
	std::cout << "School parameterized constructor is called" << std::endl;
}

School::School()
{
    std::cout << "School default constructor is called" << std::endl;
}

/*Destructors*/
School::~School( void )
{
	delete _hm;
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


