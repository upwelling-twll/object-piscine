#ifndef PROFESSOR_HPP
# define PROFESSOR_HPP

# include <iostream>
# include "Staff.hpp"
# include "../objects/Course.hpp"
class Course;
class Professor : public Staff
{
private:
    // Add member variables here
	Course* _currentCourse;

public:
	/*Member functions*/
    void assignCourse(Course* p_course);
	void doClass();
	void closeCourse();

	/*Getters and Setters*/

	/*Constructors*/
    Professor(std::string name);

	// /*Destructors*/
    ~Professor( void );

	// /*Overload operators*/
};

std::ostream& operator<<(std::ostream &output_stream, Professor& src);

#endif // PROFESSOR_HPP
