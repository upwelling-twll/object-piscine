#include "Worker.hpp"
#include "Tool.hpp"


/*Member functions*/
void Worker::useTool(Tool* tool)
{
	if (!tool)
	{
		throw "No tool to use." ;
		return;
	}
    tool->use();
}

void Worker::takeTool(Tool* tool)
{
	if (!tool)
	{
		throw "No tool to take." ;
		return;
	}
	if (tool->getMemberOfUse() && tool->getMemberOfUse() == this)
	{
		std::cout << "Worker " << this->_name << " already has this tool." << std::endl;
		return;
	}
	if (tool->getMemberOfUse() && tool->getMemberOfUse() != this)
	{
		tool->getMemberOfUse()->discardTool(tool);
		tool->setMemberOfUse(this);
	}
	this->_tools.push_back(tool);
	std::cout << "Worker " << this->_name << " has taken a tool." << std::endl;
}

void Worker::discardTool(Tool* tool)
{
	if (this->_tools.empty())
	{
		throw "Worker " + this->_name + " has no tools to discard." ;
	}
	for (std::vector<Tool*>::iterator it = this->_tools.begin(); it != this->_tools.end(); ++it)
	{
		if (*it == tool)
		{
			this->_tools.erase(it);
			tool->setMemberOfUse(NULL);
			std::cout << "Worker " << this->_name << " has discarded a tool." << std::endl;
			return;
		}
	}
	throw "Tool not found in " + this->_name + "'s inventory." ;
}

/*Getters and Setters*/
const std::string Worker::getName() const
{
	return this->_name;
}

Position& Worker::getPosition()
{
	return this->_pos;
}

Statistic& Worker::getStats()
{
	return this->_stats;
}

int Worker::getNumberOfTools() const
{
	return this->_tools.size();
}



/*Constructors*/
Worker::Worker(std::string _name) : _name(_name)
{
	Position pos;
	Statistic stats;
	
	pos.x = 0;
	pos.y = 0;
	pos.z = 0;

	stats.level = 1;
	stats.experience = 0;

	this->_pos = pos;
	this->_stats = stats;

	this->_tools = std::vector<Tool*>();
	std::cout << "Worker parameterized constructor is called" << std::endl;
}

/*Destructors*/
Worker::~Worker( void )
{
    std::cout << "Worker destructor is called" << std::endl;
	if (!this->_tools.empty())
	{
		std::cout << "Worker " << this->_name << " is discarding their tools." << std::endl;
		
	}
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, Worker& src)
{
	Position pos = src.getPosition();
	Statistic stats = src.getStats();
	int tool_count = src.getNumberOfTools();
	output_stream << "* Worker Class info*" << std::endl;
	output_stream << "Name: " << src.getName() << std::endl;
	output_stream << "Position: (" << pos.x << ", " << pos.y << ", " << pos.z << ")" << std::endl;
	output_stream << "Level: " << stats.level << std::endl;
	output_stream << "Experience: " << stats.experience << std::endl;	
	output_stream << "Tools number: " << tool_count << std::endl;
	return output_stream;
}

