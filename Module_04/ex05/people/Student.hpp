#ifndef STUDENT_HPP
# define STUDENT_HPP

# include <iostream>
# include <vector>
# include <map>
# include <random>


# include "IPerson.hpp"
# include "../courses/Course.hpp"
# include "../rooms/Classroom.hpp"

// class Course;
// class Classroom;
class Headmaster;
class Courtyard;

class Student : public IPerson
{
private:
    std::vector<Course*>	_subscribedCourse;
	std::map<Course*, int>	_attendance;
	int						_level;

public:
	/*Member functions*/
	Room* findRecreationSpace();
    void attendClass(Classroom* p_classroom);
	void exitClass();
	void graduate(Course* p_course);
	void addCourse(Course* p_course);
	void update(Break _break);

	Course* findCourse(Course* p_course);
	Course* findUniqueCourse();
	void	addAttendance(Course* p_course);
	void	prepareForClass(Headmaster* hm);

	/*Getters and Setters*/
	const std::vector<Course*>	getCourses() const;
	int							getAttendance(Course* p_course);
	int							getLevel();

	/*Constructors*/
    Student(std::string name);

	/*Destructors*/
    ~Student( void );

	/*Overload operators*/
};

std::ostream& operator<<(std::ostream &output_stream, Student& src);

#endif // STUDENT_HPP
