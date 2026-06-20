#ifndef STAFF_HPP
# define STAFF_HPP

# include <iostream>
# include "Person.hpp"

class Form;

class Staff : public Person
{
private:
    

public:
	/*Member functions*/
    void sign(Form* p_form);

	/*Getters and Setters*/

	/*Constructors*/
    Staff(std::string name);

	// /*Destructors*/
    ~Staff( void );

	// /*Overload operators*/
};

// std::ostream& operator<<(std::ostream &output_stream, Staff& src);

#endif // STAFF_HPP
