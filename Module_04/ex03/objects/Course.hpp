#ifndef COURSE_HPP
# define COURSE_HPP

# include <iostream>
# include <vector>
// # include "../people/Professor.hpp"

class Student;
class Professor;
class Classroom;
class Course
{
private:

	std::string				_name;
	Professor*				_responsable;
	std::vector<Student*>	_students;
	int 					_numberOfClassToGraduate;
	int						_maximumNumberOfStudent;
	Classroom*				_currentRoom;

public:

	Course(std::string p_name, int numberOfClassToGraduate, int maxNumberOfStudents);
	~Course( void );
	
	void	assign(Professor* p_professor);
	void	subscribe(Student* p_student);
	Student* findStudent(Student* p_student);
	void	holdClass();

	std::string getName();
	Professor*	getResponsable();
	int			getNumberOfStudents();
	int			getNumberOfClasses();
	int			getMaxStudents();
	Classroom*	getClassroom();
	void		setFinished();
	void		setClassroom(Classroom* p_classroom);
};

std::ostream& operator<<(std::ostream &output_stream, Course& src);

#endif // COURSE_HPP
