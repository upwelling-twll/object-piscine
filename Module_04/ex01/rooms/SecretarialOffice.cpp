#include "SecretarialOffice.hpp"

/*Member functions*/

/*Getters and Setters*/
// std::vector<Form*> SecretarialOffice::getArchivedForms()
// {
//     if (!_archivedForms)
//         return (NULL);
//     else
//     {
//         return (_archivedForms.size());
//     }
// }
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
    // std::vector<Form*> af;
	// af = src.getArchivedForms();
	// if (!af)
		output_stream << "Archived forms: 0" << std::endl;
	// output_stream << "Archived forms: " << af->size() << std::endl;
	output_stream << static_cast<Room&>(src) << std::endl;
	return output_stream;
}

