#include "Classroom.hpp"

/*Member functions*/
void Classroom::method()
{
    // Method implementation
}

/*Getters and Setters*/

/*Constructors*/
Classroom::Classroom(/*Parameterized Constructor*/)
{
   std::cout << "Classroom parameterized constructor is called" << std::endl;
}

Classroom::Classroom()
{
    std::cout << "Classroom default constructor is called" << std::endl;
}

/*Destructors*/
Classroom::~Classroom( void )
{
    std::cout << "Classroom destructor is called" << std::endl;
}

/*Overload operators*/
Classroom& Classroom::operator=(const Classroom& src)
{
	std::cout << "Classroom copy assignment is called" << std::endl;
	if (this != &src)
	{
		// Assinment variables
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& output_stream, Classroom& src)
{
	output_stream << "* Classroom Class info*" << std::endl;
	return output_stream;
}

