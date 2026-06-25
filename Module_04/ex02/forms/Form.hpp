#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "../FormType.hpp"
# include "../Debug.hpp"
class Form
{
private:
   FormType _formType;
   bool		_signStatus;
   bool		_execStatus;

public:
	/*Member functions*/
	virtual void execute() = 0;
	
	/*Getters and Setters*/
	bool getSignStatus();
	bool getExecStatus();

	FormType getType();
	
	/*Constructors*/
	Form(FormType p_formType);
	
	/*Destructors*/
    virtual ~Form( void );

	// /*Overload operators*/
};

// std::ostream& operator<<(std::ostream &output_stream, Form& src);

#endif // FORM_HPP
