#include "Tool.hpp"
#include "Worker.hpp"

/*Member functions*/

/*Getters and Setters*/
void Tool::setOwner(Worker* owner)
{
	if (owner)
	{
		this->_owner = owner;
		std::cout << "Tool " << this->_name << " is now owned by " << owner->getName() << "." << std::endl;
	}
	else
	{
		this->_owner = NULL;
		std::cout << "Tool " << this->_name << " has been lost." << std::endl;
	}
}

/*Constructors*/
Tool::Tool(std::string& _name) : _name(_name), _owner(NULL)
{
   std::cout << "Tool parameterized constructor is called" << std::endl;
}

Tool::Tool()
{
    std::cout << "Tool default constructor is called" << std::endl;
}

/*Destructors*/
Tool::~Tool( void )
{
    std::cout << "Tool destructor is called" << std::endl;
}

/*Overload operators*/
Tool& Tool::operator=(const Tool& src)
{
	std::cout << "Tool copy assignment is called" << std::endl;
	if (this != &src)
	{
		// Assinment variables
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& output_stream, Tool& src)
{
	output_stream << INFO << "* Tool Class info*" << std::endl;
	output_stream << "Name: " << src.getName() << std::endl;
	output_stream << "Owner: " << src.getOwner() << std::endl;
	return output_stream;
}

