#ifndef SECRETARY_HPP
# define SECRETARY_HPP

# include <iostream>
# include "../forms/Form.hpp"
# include "Staff.hpp"

// class Form;

class Secretary : public Staff
{
private:
    // Add member variables here
	void sendFormToArchive(Form* p_form);

public:
	/*Member functions*/
	Form* createForm(FormType p_formType, time_t expiration);
	void archiveForm(Form* p_form);
	// void update(Break _break);

	/*Getters and Setters*/

	/*Constructors*/
    Secretary(std::string name);

	/*Destructors*/
    ~Secretary( void );

	// /*Overload operators*/
};

std::ostream& operator<<(std::ostream &output_stream, Secretary& src);

#endif // SECRETARY_HPP
