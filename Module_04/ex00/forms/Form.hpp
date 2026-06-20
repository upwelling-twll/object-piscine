#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "../FormType.hpp"

class Form
{
private:
   FormType _formType;

public:
	/*Member functions*/
	virtual void execute() = 0;
	
	/*Getters and Setters*/
	
	/*Constructors*/
	Form(FormType p_formType);
	
	/*Destructors*/
    ~Form( void );

	// /*Overload operators*/
};

// std::ostream& operator<<(std::ostream &output_stream, Form& src);

#endif // FORM_HPP
