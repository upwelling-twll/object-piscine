#ifndef COURSE_HPP
# define COURSE_HPP

# include <iostream>
# include <vector>

class Student;
class Professor;

class Course
{
private:

	std::string				_name;
	Professor*				_responsable;
	std::vector<Student*>	_students;
	int 					_numberOfClassToGraduate;
	int						_maximumNumberOfStudent;

public:

	Course(std::string p_name, int numberOfClassToGraduate, int maxNumberOfStudents);
	void	assign(Professor* p_professor);
	void	subscribe(Student* p_student);

	std::string getName();
};

std::ostream& operator<<(std::ostream &output_stream, Course& src);

#endif // COURSE_HPP
