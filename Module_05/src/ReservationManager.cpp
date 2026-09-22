#include "ReservationManager.hpp"

/*Member functions*/
void ReservationManager::method()
{
    // Method implementation
}

/*Getters and Setters*/

/*Constructors*/
ReservationManager::ReservationManager(/*Parameterized Constructor*/)
{
   std::cout << "ReservationManager parameterized constructor is called" << std::endl;
}

ReservationManager::ReservationManager()
{
    std::cout << "ReservationManager default constructor is called" << std::endl;
}

/*Destructors*/
ReservationManager::~ReservationManager( void )
{
    std::cout << "ReservationManager destructor is called" << std::endl;
}

/*Overload operators*/
ReservationManager& ReservationManager::operator=(const ReservationManager& src)
{
	std::cout << "ReservationManager copy assignment is called" << std::endl;
	if (this != &src)
	{
		// Assinment variables
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& output_stream, ReservationManager& src)
{
	output_stream << "* ReservationManager Class info*" << std::endl;
	return output_stream;
}

