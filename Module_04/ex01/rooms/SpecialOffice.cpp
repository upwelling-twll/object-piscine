#include "SecretarialOffice.hpp"

/*Member functions*/
void SecretarialOffice::method()
{
    // Method implementation
}

/*Getters and Setters*/

/*Constructors*/
SecretarialOffice::SecretarialOffice(/*Parameterized Constructor*/)
{
   std::cout << "SecretarialOffice parameterized constructor is called" << std::endl;
}

SecretarialOffice::SecretarialOffice()
{
    std::cout << "SecretarialOffice default constructor is called" << std::endl;
}

/*Destructors*/
SecretarialOffice::~SecretarialOffice( void )
{
    std::cout << "SecretarialOffice destructor is called" << std::endl;
}

/*Overload operators*/
SecretarialOffice& SecretarialOffice::operator=(const SecretarialOffice& src)
{
	std::cout << "SecretarialOffice copy assignment is called" << std::endl;
	if (this != &src)
	{
		// Assinment variables
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& output_stream, SecretarialOffice& src)
{
	output_stream << "* SecretarialOffice Class info*" << std::endl;
	return output_stream;
}

