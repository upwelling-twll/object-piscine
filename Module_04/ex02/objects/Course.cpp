#include "Course.hpp"
#include "../Debug.hpp"
# include "../people/Professor.hpp"

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

Professor* Course::getResponsable()
{
	return (_responsable);
}

int Course::getNumberOfStudents()
{
	return (_students.size());
}

int Course::getNumberOfClasses()
{
	return (_numberOfClassToGraduate);
}

int Course::getMaxStudents()
{
	return (_maximumNumberOfStudent);
}
/*Constructors*/
Course::Course(std::string p_name, int numberOfClassToGraduate, int maxNumberOfStudents) 
	: _name(p_name), _responsable(NULL), _numberOfClassToGraduate(numberOfClassToGraduate), _maximumNumberOfStudent(maxNumberOfStudents)
{
    LOG_CTOR("Course parameterized constructor is called");
}

/*Destructors*/
Course::~Course( void )
{
    LOG_DTOR("Course destructor is called");
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, Course& src)
{
	output_stream << "* Course Class info*" << std::endl;
	output_stream << " Name : " << src.getName() << std::endl;
	if (src.getResponsable() == NULL)
		output_stream << " Professor assigned : null" << std::endl;
	else
		output_stream << "Professor assigned : " << (src.getResponsable())->getName() << std::endl;
	output_stream << " Number of students currently assigned : " << src.getNumberOfStudents() << std::endl;
	output_stream << " Number of class to graduate : " << src.getNumberOfClasses() << std::endl;
	output_stream << " Maxnumber of students : " << src.getMaxStudents()<< std::endl;

	return output_stream;
}

