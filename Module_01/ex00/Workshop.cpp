#include "Workshop.hpp"
#include "Worker.hpp"

/*Member functions*/
void Workshop::registerWorker(Worker* worker)
{
    if (!worker)
	{
		throw "No worker to register.";
		return;
	}
	for (std::vector<Worker*>::iterator it = this->_workers.begin(); it != this->_workers.end(); ++it)
	{
		if (*it == worker)
		{
			std::cout << GREEN << "Worker " << worker->getName() << " is already registered in this workshop." << RESET << std::endl;
			return;
		}
	}
	worker->registerInWorkshop(this);
	this->_workers.push_back(worker);
	std::cout << "Worker " << worker->getName() << " has been registered in the workshop." << std::endl;
}

void Workshop::releaseWorker(Worker* worker)
{
	if (!worker)
	{
		throw "No worker to release.";
		return;
	}
	for (std::vector<Worker*>::iterator it = this->_workers.begin(); it != this->_workers.end(); ++it)
	{
		if (*it == worker)
		{
			this->_workers.erase(it);
			worker->leaveWorkshop(this);
			std::cout << "Worker " << worker->getName()<< " has been released from the workshop." << std::endl;
			return;
		}
	}
	throw "Worker not found in this workshop.";
}

void Workshop::displayWorkers() const
{
	std::cout << GREEN << "Workers registered in " << this->_name << ":" << RESET << std::endl;
	for (std::vector<Worker*>::const_iterator it = this->_workers.begin(); it != this->_workers.end(); ++it)
	{
		std::cout << GREEN << "- " << (*it)->getName() << RESET << std::endl;
	}
}

/*Getters and Setters*/
const std::string& Workshop::getName() const
{
	return this->_name;
}

/*Constructors*/

Workshop::Workshop(std::string name) : _name(name)
{
	std::cout << GREEN << "Workshop " << _name << " is created" << RESET << std::endl;
	this->_workers = std::vector<Worker*>();
}

Workshop::Workshop() : _name("Default Workshop")
{
    std::cout << GREEN << "Workshop " << _name << " is created" << RESET << std::endl;
	this->_workers = std::vector<Worker*>();
}

/*Destructors*/
Workshop::~Workshop( void )
{
    std::cout << GREEN << "Workshop destructor is called" << RESET << std::endl;
	for (std::vector<Worker*>::iterator it = this->_workers.begin(); it != this->_workers.end(); ++it)
	{
		if (*it)
		{
			std::cout << "Releasing worker: " << (*it)->getName() << std::endl;
			(*it)->leaveWorkshop(this);
		}
	}
}


