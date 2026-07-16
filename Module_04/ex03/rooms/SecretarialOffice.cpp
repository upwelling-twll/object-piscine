#include "SecretarialOffice.hpp"
#include "../Debug.hpp"
#include "../forms/Form.hpp"
#include <algorithm>

/*Member functions*/
void SecretarialOffice::addToArchive(Form* p_form)
{
	if (!p_form)
		std::invalid_argument("SecretarialOffice addToArchive() received null form");
	else
	{
		// don't check duplicate by pointer (unique ownership), just store
		_archivedForms.push_back(p_form);
		LOG_ACTION("SecretarialOffice: form was archived");
	}
}

/*Getters and Setters*/

int SecretarialOffice::getArchivedForms()
{
	return (_archivedForms.size());
}

/*Constructors*/
SecretarialOffice::SecretarialOffice()
{
	LOG_CTOR("SecretarialOffice parameterized constructor is called");
}

/*Destructors*/
SecretarialOffice::~SecretarialOffice( void )
{
	LOG_DTOR("SecretarialOffice destructor is called");
	for (std::vector<Form*>::iterator it = _archivedForms.begin(); it != _archivedForms.end(); ++it)
	{
		delete(*it);
	}
	_archivedForms.clear();
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

