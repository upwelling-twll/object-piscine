#include "Tool.hpp"
#include "Worker.hpp"

/*Member functions*/

/*Getters and Setters*/
void Tool::setMemberOfUse(Worker* memberOfUse)
{
	if (memberOfUse)
	{
		this->_memberOfUse = memberOfUse;
		std::cout << WHITE << "Tool " << this->_name << " is now owned by " << memberOfUse->getName() << "." << RESET<< std::endl;
	}
	else
	{
		this->_memberOfUse = NULL;
		std::cout << WHITE << "Tool " << this->_name << " has been lost." << RESET << std::endl;
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

int Tool::getNumberOfUses() const
{
	return this->_numberOfUses;
}

const std::string& Tool::getName() const
{
	return this->_name;
}

/*Constructors*/
Tool::Tool(const std::string& _name) : _name(_name), _memberOfUse(NULL),
	_numberOfUses(0)
{
//    std::cout << "Tool parameterized constructor is called" << std::endl;
}

Tool::Tool() : _name("Unknown"), _memberOfUse(NULL), _numberOfUses(0)
{
    // std::cout << "Tool default constructor is called" << std::endl;
}

/*Destructors*/
Tool::~Tool( void )
{
    // std::cout << "Tool destructor is called" << std::endl;
	if (this->_memberOfUse)
	{
		this->_memberOfUse->discardTool(this);
	}

}

std::ostream& operator<<(std::ostream& output_stream, Tool& src)
{
	std::string name = "None";
	if (src.getMemberOfUse())
	{
		name = src.getMemberOfUse()->getName();
	}
	output_stream << "* Tool Class info*" << std::endl;
	output_stream << "Name: " << src.getName() << std::endl;
	output_stream << "memberOfUse: " << name << std::endl;
	output_stream << "Number of uses: " << src.getNumberOfUses() << std::endl;
	return output_stream;
}

