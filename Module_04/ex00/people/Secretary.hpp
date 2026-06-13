#ifndef SECRETARY_HPP
# define SECRETARY_HPP

# include <iostream>

class Secretary : public Staff
{
private:
    // Add member variables here

public:
	/*Member functions*/
	Form* createForm(FormType p_formType);
	void archiveForm();

	/*Getters and Setters*/

	/*Constructors*/
    // Secretary(/*Parameterized Constructor*/);
	// Secretary(void);

	// /*Destructors*/
    // ~Secretary( void );

	// /*Overload operators*/
	// Secretary &operator=(const Secretary& src);
};

// std::ostream& operator<<(std::ostream &output_stream, Secretary& src);

#endif // SECRETARY_HPP
