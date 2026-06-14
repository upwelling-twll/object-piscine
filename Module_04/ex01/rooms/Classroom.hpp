#ifndef CLASSROOM_HPP
# define CLASSROOM_HPP

# include <iostream>
# include "Room.hpp"

class Course;

class Classroom : public Room
{
private:

	Course* _currentRoom;

public:

	Classroom();
	void assignCourse(Course* p_course);
};

std::ostream& operator<<(std::ostream &output_stream, Classroom& src);

#endif // CLASSROOM_HPP
