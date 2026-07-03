#ifndef HEADMASTER_HPP
# define HEADMASTER_HPP

# include <iostream>
# include <vector>

# include "Staff.hpp"
# include "../forms/forms.hpp"
# include "../bell/Bell.hpp"


// class Staff;
// class Form;
class NeedCourseCreationForm;
class NeedMoreClassRoomForm;
class SubscriptionToCourseForm;
class CourseFinishedForm;
class Course;
class Secretary;

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
	void update(Break _break);

    void conductClasses();
    void ringBell(Bell* bell);

    //requests from staff & students
    // Form* graduateFromCourse();
    NeedMoreClassRoomForm*      needRoom();
    NeedCourseCreationForm*     needCourse();
    SubscriptionToCourseForm*   subscribeToCourse();
    CourseFinishedForm*         graduateStudent();

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
