#ifndef PROFESSOR_HPP
# define PROFESSOR_HPP

# include <iostream>

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
    // Professor(/*Parameterized Constructor*/);
	// Professor(void);

	// /*Destructors*/
    // ~Professor( void );

	// /*Overload operators*/
	// Professor &operator=(const Professor& src);
};

// std::ostream& operator<<(std::ostream &output_stream, Professor& src);

#endif // PROFESSOR_HPP
