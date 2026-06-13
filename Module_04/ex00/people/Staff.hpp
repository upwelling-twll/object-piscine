#ifndef STAFF_HPP
# define STAFF_HPP

# include <iostream>
# include "Person.hpp"

class Form;

class Staff : public Person
{
private:
    // Add member variables here

public:
	/*Member functions*/
    void sign(Form* p_form);

	/*Getters and Setters*/

	/*Constructors*/
    // Staff(/*Parameterized Constructor*/);
	// Staff(void);

	// /*Destructors*/
    // ~Staff( void );

	// /*Overload operators*/
	// Staff &operator=(const Staff& src);
};

// std::ostream& operator<<(std::ostream &output_stream, Staff& src);

#endif // STAFF_HPP
