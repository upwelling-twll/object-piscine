#include "Hammer.hpp"
#include "Worker.hpp"

/*Member functions*/
void Hammer::use()
{
	if (!this->_memberOfUse)
	{
		throw std::runtime_error("No worker to use the Hammer.");
		return;
	}
	std::cout << PINK << "🔨 Worker " << this->_memberOfUse->getName() << " is using the Hammer.🔨" << RESET << std::endl;
	this->_numberOfUses++;
}

/*Constructors*/
Hammer::Hammer(const std::string& _name, const std::string& _type) : Tool(_name, _type)
{
//    std::cout << "Hammer parameterized constructor is called" << std::endl;
}

Hammer::Hammer() : Tool()
{
    // std::cout << "Hammer default constructor is called" << std::endl;
}

/*Destructors*/
Hammer::~Hammer( void )
{
    // std::cout << "Hammer destructor is called" << std::endl;
}

