#include "Shover.hpp"
#include "Worker.hpp"

/*Member functions*/
void Shover::use()
{
	if (!this->_memberOfUse)
	{
		throw "No worker to use the shover." ;
		return;
	}
	std::cout << "Worker " << this->_memberOfUse->getName() << " is using the shover." << std::endl;
	this->_numberOfUses++;
}

/*Constructors*/
Shover::Shover(const std::string& _name) : Tool(_name)
{
   std::cout << "Shover parameterized constructor is called" << std::endl;
}

Shover::Shover() : Tool()
{
    std::cout << "Shover default constructor is called" << std::endl;
}

/*Destructors*/
Shover::~Shover( void )
{
    std::cout << "Shover destructor is called" << std::endl;
}

