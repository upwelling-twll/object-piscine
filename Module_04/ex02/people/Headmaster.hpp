#ifndef HEADMASTER_HPP
# define HEADMASTER_HPP

# include <iostream>
# include <vector>

# include "../forms/Form.hpp"
# include "Staff.hpp"


// class Staff;
// class Form;
class Course;

class Headmaster : public Staff
{
private:
    std::vector<Form*> _formToValidate;
	std::vector<Course*> _courses;

public:
	/*Member functions*/
    void receiveForm(Form* p_form);
    void sign(Form* p_form);
    void execute(Form* p_form);


	/*Getters and Setters*/
    std::vector<Course*> getCourses();

	/*Constructors*/
    Headmaster(std::string name);

	// /*Destructors*/
    ~Headmaster( void );

	// /*Overload operators*/
};

std::ostream& operator<<(std::ostream &output_stream, Headmaster& src);

#endif // HEADMASTER_HPP
