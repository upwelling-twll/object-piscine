#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Form
{
private:
   FormType _formType;

public:
	/*Member functions*/
   	Form(FormType p_formType)
	{

	}

	virtual void execute() = 0;

	/*Getters and Setters*/

	/*Constructors*/
    // Form(/*Parameterized Constructor*/);
	// Form(void);

	// /*Destructors*/
    // ~Form( void );

	// /*Overload operators*/
	// Form &operator=(const Form& src);
};

// std::ostream& operator<<(std::ostream &output_stream, Form& src);

#endif // FORM_HPP
