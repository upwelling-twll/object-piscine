#include "Worker.hpp"

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

/*Getters and Setters*/

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
		for (Tool* tool : this->_tools)
		{
			if (tool)
			{
				delete tool;
			}
		}
	}
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, Worker& src)
{
	output_stream << "* Worker Class info*" << std::endl;
	output_stream << "Name: " << src.getName() << std::endl;
	return output_stream;
}

