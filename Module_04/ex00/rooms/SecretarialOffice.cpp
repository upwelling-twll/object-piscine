#include "SecretarialOffice.hpp"

/*Member functions*/

/*Getters and Setters*/

/*Constructors*/
SecretarialOffice::SecretarialOffice(int ID) : Room(ID)
{
   std::cout << "SecretarialOffice parameterized constructor is called" << std::endl;
}

/*Destructors*/
SecretarialOffice::~SecretarialOffice( void )
{
    std::cout << "SecretarialOffice destructor is called" << std::endl;
}

/*Overload operators*/

std::ostream& operator<<(std::ostream& output_stream, SecretarialOffice& src)
{
	output_stream << "* SecretarialOffice Class info*" << std::endl;
	return output_stream;
}

