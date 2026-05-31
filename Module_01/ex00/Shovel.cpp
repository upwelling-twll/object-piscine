#include "Shovel.hpp"
#include "Worker.hpp"

/*Member functions*/
void Shovel::use()
{
	if (!this->_memberOfUse)
	{
		throw std::runtime_error("No worker to use the Shovel.");
		return;
	}
	std::cout << BLUE << "🪏 Worker " << this->_memberOfUse->getName() << " is using the Shovel.🪏 " << RESET << std::endl;
	this->_numberOfUses++;
}

/*Constructors*/
Shovel::Shovel(const std::string& _name) : Tool(_name)
{
//    std::cout << "Shovel parameterized constructor is called" << std::endl;
}

Shovel::Shovel() : Tool()
{
    // std::cout << "Shovel default constructor is called" << std::endl;
}

/*Destructors*/
Shovel::~Shovel( void )
{
    // std::cout << "Shovel destructor is called" << std::endl;
}

