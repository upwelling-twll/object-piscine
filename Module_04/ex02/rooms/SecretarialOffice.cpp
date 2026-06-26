#include "SecretarialOffice.hpp"
#include "../Debug.hpp"

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
SecretarialOffice::SecretarialOffice()
{
	LOG_CTOR("SecretarialOffice parameterized constructor is called");
}

/*Destructors*/
SecretarialOffice::~SecretarialOffice( void )
{
	LOG_DTOR("SecretarialOffice destructor is called");
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

