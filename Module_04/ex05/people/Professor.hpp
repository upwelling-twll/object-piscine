#ifndef PROFESSOR_HPP
# define PROFESSOR_HPP

# include <iostream>
# include "Staff.hpp"
# include "../courses/Course.hpp"

class Headmaster;
class Course;
class Room;
class Professor : public Staff
{
private:
    // Add member variables here
	Course*			_currentCourse;
	Headmaster*		_hm;

public:
	/*Member functions*/
    void 	assignCourse(Course* p_course);
	void	prepareForClass();
	void 	doClass();
	void 	closeCourse();
	void 	studentHadEnoughClasses(Student* p_student, Course* p_course);
	Classroom*	findFreeClassroom();
	void update(Break _break);

	/*Getters and Setters*/
	void setHeadmaster(Headmaster* p_hm);
	Headmaster*	getHeadmaster();

	/*Constructors*/
    Professor(std::string name);

	// /*Destructors*/
    ~Professor( void );

	// /*Overload operators*/
};

std::ostream& operator<<(std::ostream &output_stream, Professor& src);

#endif // PROFESSOR_HPP
