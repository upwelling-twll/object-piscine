#ifndef SECRETARY_HPP
# define SECRETARY_HPP

# include <iostream>
# include "../FormType.hpp"
# include "Staff.hpp"

class Form;

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
    Secretary(std::string name);

	/*Destructors*/
    ~Secretary( void );

	// /*Overload operators*/
};

std::ostream& operator<<(std::ostream &output_stream, Secretary& src);

#endif // SECRETARY_HPP
