#ifndef SUBSCRIPTIONTOCOURSEFORM_HPP
# define SUBSCRIPTIONTOCOURSEFORM_HPP

# include <iostream>
# include "Form.hpp"

class Course;
class Student;

class SubscriptionToCourseForm : public Form
{
private:
	Course*		p_course;
	Student*	p_student;

	bool		courseSet;
	bool		studentSet;

public:
	/*Member functions*/
   void execute(Headmaster *hm);
   bool isComplete();

	/*Getters and Setters*/
	void setStudent(Student* student);
	void setCourse(Course* course);

	/*Constructors*/
    SubscriptionToCourseForm(FormType type, time_t expirationDate);

	/*Destructors*/
    ~SubscriptionToCourseForm( void );

	// /*Overload operators*/
};

std::ostream& operator<<(std::ostream &output_stream, SubscriptionToCourseForm& src);

#endif // SUBSCRIPTIONTOCOURSEFORM_HPP
