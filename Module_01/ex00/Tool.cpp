#include "Tool.hpp"
#include "Worker.hpp"

/*Member functions*/

/*Getters and Setters*/
void Tool::setMemberOfUse(Worker* memberOfUse)
{
	if (memberOfUse)
	{
		this->_memberOfUse = memberOfUse;
		std::cout << "Tool " << this->_name << " is now owned by " << memberOfUse->getName() << "." << std::endl;
	}
	else
	{
		this->_memberOfUse = NULL;
		std::cout << "Tool " << this->_name << " has been lost." << std::endl;
	}
}

Worker* Tool::getMemberOfUse() const
{
	if (this->_memberOfUse)
	{
		return this->_memberOfUse;
	}
	else
	{
		return NULL;
	}
}

const std::string& Tool::getName() const
{
	return this->_name;
}

/*Constructors*/
Tool::Tool(const std::string& _name) : _name(_name), _memberOfUse(NULL),
	_numberOfUses(0)
{
   std::cout << "Tool parameterized constructor is called" << std::endl;
}

Tool::Tool() : _name("Unknown"), _memberOfUse(NULL), _numberOfUses(0)
{
    std::cout << "Tool default constructor is called" << std::endl;
}

/*Destructors*/
Tool::~Tool( void )
{
    std::cout << "Tool destructor is called" << std::endl;
}

std::ostream& operator<<(std::ostream& output_stream, Tool& src)
{
	output_stream << INFO << "* Tool Class info*" << std::endl;
	output_stream << "Name: " << src.getName() << std::endl;
	output_stream << "memberOfUse: " << src.getMemberOfUse() << std::endl;
	return output_stream;
}

