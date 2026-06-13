#ifndef HEADMASTER_HPP
# define HEADMASTER_HPP

# include <iostream>
# include <vector>

# include "Staff.hpp"

class Form;
class Headmaster : public Staff
{
private:
    std::vector<Form*> _formToValidate;

public:
	/*Member functions*/
    void receiveForm(Form* p_form);

	/*Getters and Setters*/

	/*Constructors*/
    // Headmaster(/*Parameterized Constructor*/);
	// Headmaster(void);

	// /*Destructors*/
    // ~Headmaster( void );

	// /*Overload operators*/
	// Headmaster &operator=(const Headmaster& src);
};

// std::ostream& operator<<(std::ostream &output_stream, Headmaster& src);

#endif // HEADMASTER_HPP
