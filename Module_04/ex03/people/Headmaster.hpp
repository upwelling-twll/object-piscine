#ifndef HEADMASTER_HPP
# define HEADMASTER_HPP

# include <iostream>
# include <vector>

# include "Staff.hpp"
# include "../forms/Form.hpp"


// class Staff;
// class Form;
class Course;

class Headmaster : public Staff
{
private:
    std::vector<Form*> _formToValidate;
    Secretary* p_secretary;

public:
	/*Member functions*/
    void receiveForm(Form* p_form);
    void sign(Form* p_form);
    void execute(Form* p_form);

    void launchCourses();

    //requests from staff & students
    Form* needCourse();
    // Form* graduateFromCourse();
    Form* subscribeToCourse();
    Form* needRoom();
    Form* finishCourse();

	/*Getters and Setters*/
    void    setSecretary(Secretary* s);


	/*Constructors*/
    Headmaster(std::string name);

	// /*Destructors*/
    ~Headmaster( void );

	// /*Overload operators*/
};

std::ostream& operator<<(std::ostream &output_stream, Headmaster& src);

#endif // HEADMASTER_HPP
