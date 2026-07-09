#ifndef SCHOOL_HPP
# define SCHOOL_HPP

# include <iostream>

#include "FormType.hpp"
#include "courses/Course.hpp"
#include "bell/Bell.hpp"
#include "forms/forms.hpp"
#include "people/people.hpp"
#include "rooms/rooms.hpp"
#include "singletons.hpp"
#include "Debug.hpp"
#include "courses/CourseBlueprint.hpp"

class School
{
private:
    Headmaster*			_hm;
	Secretary*			_sec;
	const std::string	_schoolName;
	Bell				_bell;

	// SingleList<Student>& students;
 	// SingleList<Course>& courses;
	// SingleList<Staff>& staff;
	// SingleList<Professor>& professors;
	// SingleList<Room>& rooms;

public:
	/*Member functions*/
    void runDayRoutine(); //execute the school day routine
	void launchClasses(); //Make the headmaster ask the students and professors to attend them classes
	void requestRingBell(); //Make the headmaster ring the bell
	void recruteProfessor(Professor* p); //Add a new professor to the school
	void recruteStudent(Student* s); // Add a new student to the school
	void graduationCeremony(); //launch the graduation of every student that can graduate at a desired moment
	
	
	/*Getters and Setters*/
	Course*					getCourse(std::string p_name); //return a course with a given name
	std::vector<Student*>	getStudents(); //return a vector containing every student in school
	std::vector<Professor*>	getProfessors(); //return a vector containing every professor in school
	std::vector<Course*>	getCourses(); //return a vector containing every course in school
	Headmaster*				getHeadmaster(); //return the headmaster of the school
	Secretary*				getSecretary(); // return the secretary of the school

	/*Constructors*/
    School(std::string name);

	/*Destructors*/
    ~School( void );

	/*Overload operators*/
	School &operator=(const School& src);
};

#endif // SCHOOL_HPP
