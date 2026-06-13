#ifndef STUDENT_HPP
# define STUDENT_HPP

# include <iostream>

class Student : public Person
{
private:
    	std::vector<Course*> _subscribedCourse;


public:
	/*Member functions*/
    oid attendClass(Classroom* p_classroom);
	void exitClass();
	void graduate(Course* p_course);

	/*Getters and Setters*/

	/*Constructors*/
    // Student(/*Parameterized Constructor*/);
	// Student(void);

	// /*Destructors*/
    // ~Student( void );

	// /*Overload operators*/
	// Student &operator=(const Student& src);
};

// std::ostream& operator<<(std::ostream &output_stream, Student& src);

#endif // STUDENT_HPP
