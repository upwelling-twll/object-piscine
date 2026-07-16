#ifndef HEADMASTER_HPP
# define HEADMASTER_HPP

# include <iostream>
# include <vector>
# include <memory>

# include "Staff.hpp"
# include "../forms/forms.hpp"
# include "../bell/Bell.hpp"

#define GLEVEL 1

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
    std::vector<std::unique_ptr<Form>> _formToValidate;
    Secretary* p_secretary;

public:
	/*Member functions*/
    void receiveForm(std::unique_ptr<Form> p_form);
    void sign(Form* p_form);
    void execute(Form* p_form);
	void update(Break _break);

    void conductClasses(std::vector<Professor*> professors, std::vector<Student*> students);
    void ringBell(Bell* bell, Event eventType);
	void setStudentsAsGraduated();

    //requests from staff & students
    // Form* graduateFromCourse();
    std::unique_ptr<NeedMoreClassRoomForm>      needRoom();
    std::unique_ptr<NeedCourseCreationForm>     needCourse();
    std::unique_ptr<SubscriptionToCourseForm>   subscribeToCourse();
    std::unique_ptr<CourseFinishedForm>         graduateStudent();

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
