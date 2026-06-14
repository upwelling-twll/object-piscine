#include "Student.hpp"

/*Member functions*/
void Student::method()
{
    // Method implementation
}

/*Getters and Setters*/

/*Constructors*/
Student::Student(/*Parameterized Constructor*/)
{
   std::cout << "Student parameterized constructor is called" << std::endl;
}

Student::Student()
{
    std::cout << "Student default constructor is called" << std::endl;
}

/*Destructors*/
Student::~Student( void )
{
    std::cout << "Student destructor is called" << std::endl;
}

/*Overload operators*/
Student& Student::operator=(const Student& src)
{
	std::cout << "Student copy assignment is called" << std::endl;
	if (this != &src)
	{
		// Assinment variables
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& output_stream, Student& src)
{
	output_stream << "* Student Class info*" << std::endl;
	return output_stream;
}

