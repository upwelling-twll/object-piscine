#ifndef STUDENT_HPP
# define STUDENT_HPP

# include <iostream>
# include <vector>

# include "Person.hpp"

class Course;
class Classroom;

class Student : public Person
{
private:
    	std::vector<Course*> _subscribedCourse;


public:
	/*Member functions*/
    void attendClass(Classroom* p_classroom);
	void exitClass();
	void graduate(Course* p_course);

	/*Getters and Setters*/

	/*Constructors*/
    Student(std::string name);

	/*Destructors*/
    ~Student( void );

	/*Overload operators*/
};

std::ostream& operator<<(std::ostream &output_stream, Student& src);

#endif // STUDENT_HPP
