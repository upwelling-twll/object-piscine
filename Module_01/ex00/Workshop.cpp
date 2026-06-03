#include "Workshop.hpp"
#include "Worker.hpp"

/*Member functions*/
void Workshop::registerWorker(Worker* worker)
{
    if (!worker)
	{
		throw std::runtime_error("No worker to register in +" + this->_name + ".");
		return;
	}
	for (std::vector<Worker*>::iterator it = this->_workers.begin(); it != this->_workers.end(); ++it)
	{
		if (*it == worker)
		{
			throw std::runtime_error("Worker " + worker->getName() + " is already registered in " + this->_name + ".");
			return;
		}
	}
	if (!(worker->getTool(this->_requiredToolType)))
	{
		throw std::runtime_error("Worker " + worker->getName() + " has no tool of specific type and cannot be registered in " + this->_name + ".");
		return;
	}
	worker->registerInWorkshop(this);
	this->_workers.push_back(worker);
	std::cout << "Worker " << worker->getName() << " has been registered in the " << this->_name << std::endl;
}

void Workshop::releaseWorker(Worker* worker)
{
	if (!worker)
	{
		throw std::runtime_error("No worker to release from " + this->_name + ".");
		return;
	}
	for (std::vector<Worker*>::iterator it = this->_workers.begin(); it != this->_workers.end(); ++it)
	{
		if (*it == worker)
		{
			this->_workers.erase(it);
			worker->leaveWorkshop(this);
			std::cout << "Worker " << worker->getName()<< " has been released from the " << this->_name << std::endl;
			return;
		}
	}
	throw std::runtime_error("Worker not found in " + this->_name + " workshop.");
}

void Workshop::displayWorkers() const
{
	std::cout << GREEN << "Workers registered in " << this->_name << ":" << RESET << std::endl;
	if (this->_workers.empty())
	{
		std::cout << YELLOW << "No workers registered in the workshop." << RESET << std::endl;
		return;
	}
	for (std::vector<Worker*>::const_iterator it = this->_workers.begin(); it != this->_workers.end(); ++it)
	{
		std::cout << GREEN << "- " << (*it)->getName() << RESET << std::endl;
	}
}

void Workshop::executeWorkDay()
{
	std::cout << GREEN << "Executing work day in " << this->_name << " with " << this->_workers.size() << " workers." << RESET << std::endl;
	for (std::vector<Worker*>::iterator it = this->_workers.begin(); it != this->_workers.end(); ++it)
	{
		if (*it)
		{
			std::cout << GREEN << (*it)->getName() << " is sent to work in " << this->_name << "." << RESET << std::endl;
			(*it)->work();
		}	
	}
}

/*Getters and Setters*/
const std::string& Workshop::getName() const
{
	return this->_name;
}

const std::string& Workshop::getRequiredToolType() const
{
	return this->_requiredToolType;
}

/*Constructors*/

Workshop::Workshop(std::string name, std::string requiredToolType) : _name(name), _requiredToolType(requiredToolType)
{
	std::cout << GREEN << "Workshop " << _name << " is created" << RESET << std::endl;
	this->_workers = std::vector<Worker*>();
}

Workshop::Workshop() : _name("42"), _requiredToolType("Keyboard")
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
			std::cout << "Releasing worker: " << (*it)->getName() << "from "<< this->_name << std::endl;
			(*it)->leaveWorkshop(this);
		}
	}
}


