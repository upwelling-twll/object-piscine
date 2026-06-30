#include "Course.hpp"

/*Member functions*/
void Course::assign(Professor* p_professor)
{
	if (! p_professor)
		throw(std::invalid_argument("Course: null professor can not be assigned"));
	if (! _responsable)
		_responsable = p_professor;
	else
		std::cout << "Course already has responsable professor" << std::endl;
}

void Course::subscribe(Student* p_student)
{
   	if (! p_student)
		throw(std::invalid_argument("Course: null student can not be assigned"));
	for (std::vector<Student*>::iterator it = _students.begin(); it != _students.end(); ++it)
	{
		if (*it == p_student)
		{
			std::cout << "Course: student is already subscribed" << std::endl;
			return;
		}
	}
	_students.push_back(p_student);
}

/*Getters and Setters*/
std::string Course::getName()
{
	return (_name);
}

/*Constructors*/
Course::Course(std::string p_name, int numberOfClassToGraduate, int maxNumberOfStudents) 
	: _name(p_name), _numberOfClassToGraduate(numberOfClassToGraduate), _maximumNumberOfStudent(maxNumberOfStudents)
{
   std::cout << "Course parameterized constructor is called" << std::endl;
}

/*Destructors*/
Course::~Course( void )
{
    std::cout << "Course destructor is called" << std::endl;
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, Course& src)
{
	output_stream << "* Course Class info*" << std::endl;
	output_stream << "Name : " << std::endl;
	output_stream << "Professor assigned : " << std::endl;
	output_stream << " Number of students currently assigned : " << std::endl;
	output_stream << " Number of class to graduate : " << std::endl;
	output_stream << " Maxnumber of students : " << std::endl;

	return output_stream;
}

