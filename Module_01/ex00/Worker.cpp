#include "Worker.hpp"
#include "Tool.hpp"

/*Member functions*/

void Worker::useTool(Tool* tool)
{
	if (!tool)
	{
		throw std::runtime_error("Worker " + this->_name + " has no tool to use.");
		return;
	}
    tool->use();
}

void Worker::takeTool(Tool* tool)
{
	std::cout << "Worker " << this->_name << " is trying to take a tool " << std::endl;
	if (!tool)
	{
		throw std::runtime_error("Worker " + this->_name + " has no tool to take.");
		return;
	}
	if (tool->getMemberOfUse() && tool->getMemberOfUse() == this)
	{
		std::cout << YELLOW << "Worker " << this->_name << " already has this tool." << RESET << std::endl;
		return;
	}
	if (tool->getMemberOfUse() && tool->getMemberOfUse() != this)
	{
		tool->getMemberOfUse()->discardTool(tool);
	}
	tool->setMemberOfUse(this);
	this->_tools.push_back(tool);
	std::cout << YELLOW << "Worker " << this->_name << " has taken a tool." << RESET << std::endl;
}

void Worker::discardTool(Tool* tool)
{
	std::cout << "Worker " << this->_name << " is trying to discard a tool " << tool->getName() << std::endl;
	if (this->_tools.empty())
	{
		throw std::runtime_error("Worker " + this->_name + " has no tools to discard.");
	}
	for (std::vector<Tool*>::iterator it = this->_tools.begin(); it != this->_tools.end(); ++it)
	{
		if (*it == tool)
		{
			this->_tools.erase(it);
			tool->setMemberOfUse(NULL);
			std::cout << YELLOW << "Worker " << this->_name << " has discarded a tool." << RESET << std::endl;
			return;
		}
	}
	// for (std::vector<Workshop*>::iterator it = this->_workshops.begin(); it != this->_workshops.end(); ++it)
	// {
	// 	if (*it->getRequiredToolType() == tool->getType())
	// 	{
	// 		(*it)->releaseWorker(this);
	// 		std::cout << YELLOW << "Worker " << this->_name << " has been released from the workshop due to discarding a required tool." << RESET << std::endl;
	// 		return;
	// 	}
	// }
	throw std::runtime_error("Worker " + this->_name + " has no such tool in inventory.");
}

void Worker::registerInWorkshop(Workshop* workshop)
{
	if (!workshop)
	{
		throw std::runtime_error("Worker " + this->_name + " has no workshop to register in.");
		return;
	}
	for (std::vector<Workshop*>::iterator it = this->_workshops.begin(); it != this->_workshops.end(); ++it)
	{
		if (*it == workshop)
		{
			std::cout << YELLOW << "Worker " << this->_name << " is already registered in the workshop." << RESET << std::endl;
			return;
		}
	}
	_workshops.push_back(workshop);
	std::cout << YELLOW << "Worker " << this->_name << " added workshop" << "." << RESET << std::endl;
}

void Worker::leaveWorkshop(Workshop* workshop)
{
	if (!workshop)
	{
		throw std::runtime_error("Worker " + this->_name + " has no workshop to leave.");
		return;
	}
	for (std::vector<Workshop*>::iterator it = this->_workshops.begin(); it != this->_workshops.end(); ++it)
	{
		if (*it == workshop)
		{
			this->_workshops.erase(it);
			std::cout << YELLOW << "Worker " << this->_name << " left workshop" << "." << RESET << std::endl;
			return;
		}
	}
	throw std::runtime_error("Worker " + this->_name + " is not registered in the specified workshop.");
}

Tool* Worker::getTool(const std::string& toolType)
{
	for (std::vector<Tool*>::iterator it = this->_tools.begin(); it != this->_tools.end(); ++it)
	{
		if ((*it)->getType() == toolType)
		{
			return *it;
		}
	}
	return NULL;
}

void Worker::work()
{
	if (this->_workshops.empty())
	{
		throw std::runtime_error("Worker " + this->_name + " is unemployed and can go touch the grass.");
	}
	else
	{
		std::cout << YELLOW << "Worker " << this->_name << " is working" << RESET << std::endl;
	}
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

int Worker::getNumberOfWorkshops() const
{
	return this->_workshops.size();
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
	this->_workshops = std::vector<Workshop*>();
	// std::cout << "Worker parameterized constructor is called" << std::endl;
}

/*Destructors*/
Worker::~Worker( void )
{
    // std::cout << "Worker destructor is called" << std::endl;
	if (!this->_tools.empty())
	{
		std::cout << "Worker " << this->_name << " is discarding their tools." << std::endl;
		std::vector<Tool*>::iterator it;
		
		for (it = this->_tools.begin(); it != this->_tools.end(); ++it)
		{
			std::cout << "Discarding tool: " << (*it)->getName() << std::endl;
			if (*it)
				(*it)->setMemberOfUse(NULL);
		}
		this->_tools.clear();
		//TODO : leave all workshops
	}
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, Worker& src)
{
	Position pos = src.getPosition();
	Statistic stats = src.getStats();
	int tool_count = src.getNumberOfTools();
	int workshop_count = src.getNumberOfWorkshops();
	output_stream << "* Worker Class info*" << std::endl;
	output_stream << "Name: " << src.getName() << std::endl;
	output_stream << "Position: (" << pos.x << ", " << pos.y << ", " << pos.z << ")" << std::endl;
	output_stream << "Level: " << stats.level << std::endl;
	output_stream << "Experience: " << stats.experience << std::endl;	
	output_stream << "Tools number: " << tool_count << std::endl;
	output_stream << "Workshops number: " << workshop_count << std::endl;
	output_stream << "-----------------------" << std::endl;
	return output_stream;
}

