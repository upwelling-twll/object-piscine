#ifndef COURSEFINISHEDFORM_HPP
# define COURSEFINISHEDFORM_HPP

# include <iostream>
# include <vector>
# include "Form.hpp"

class Course;
class Headmaster;

class CourseFinishedForm : public Form
{
private:
	Course* p_course;

	bool courseSet;
    
public:
	/*Member functions*/
    void execute(Headmaster *hm);
	bool isComplete();

	/*Getters and Setters*/
	void	setCourse(Course* course);

	/*Constructors*/
    CourseFinishedForm(FormType type, time_t expirationDate);

	/*Destructors*/
    ~CourseFinishedForm( void );

	/*Overload operators*/
};

std::ostream& operator<<(std::ostream &output_stream, CourseFinishedForm& src);

#endif // COURSEFINISHEDFORM_HPP
