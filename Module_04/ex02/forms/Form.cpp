#include "Form.hpp"
#include "../Debug.hpp"

/*Member functions*/
void    Form::beSigned()
{
    if (_signStatus)
        LOG_WARNING("Form is already signed");
    else
        _signStatus = true;
}

/*Getters and Setters*/
bool Form::getSignStatus()
{
    return(_signStatus);
}

bool Form::getExecStatus()
{
    return (_execStatus);
}

FormType Form::getType()
{
    return(_formType);
}

time_t Form::getCreationDate()
{
    return (_creationDate);
}

time_t Form::getExpirationDate()
{
    return (_expirationDate);
}

/*Constructors*/
Form::Form(FormType p_formType, time_t expirationDate) : 
_formType(p_formType), _signStatus(false), _execStatus(false)
{
    time_t   _creationDate;
    time(&_creationDate);
    
    if (_creationDate < expirationDate)
        _expirationDate = expirationDate;
    else
        LOG_WARNING("Form: expiration date must be later then creation");
    _expirationDate = _creationDate;
    LOG_CTOR("Form parameterized constructor is called");
}

/*Destructors*/
Form::~Form( void )
{
    LOG_DTOR("Form destructor is called");
}

/*Overload operators*/

// std::ostream& operator<<(std::ostream& output_stream, Form& src)
// {
// 	output_stream << "* Form Class info*" << std::endl;
// 	return output_stream;
// }

