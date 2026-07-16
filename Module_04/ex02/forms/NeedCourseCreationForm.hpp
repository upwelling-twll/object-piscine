#ifndef NEEDCOURSECREATIONFORM_HPP
# define NEEDCOURSECREATIONFORM_HPP

# include <iostream>
# include "Form.hpp"
# include "../courses/Course.hpp"
# include "../people/Headmaster.hpp"


class NeedCourseCreationForm : public Form
{
private:
    std::string	courseName;
	int			classesToGraduate;
	int			maxNumberOfStudents;

	bool courseNameSet;
    bool classesToGraduateSet;
    bool maxNumberOfStudentsSet;

public:
	/*Member functions*/
    void execute(Headmaster *hm);
	bool	isComplete();


	/*Getters and Setters*/
	void	setCourseName(std::string name);
	void	setClassesToGraduate(int classes);
	void	setNumberOfStudents(int number);


	/*Constructors*/
    NeedCourseCreationForm(FormType type, time_t expirationDate);

	// /*Destructors*/
    ~NeedCourseCreationForm( void );

	// /*Overload operators*/
};

std::ostream& operator<<(std::ostream &output_stream, NeedCourseCreationForm& src);

#endif // NEEDCOURSECREATIONFORM_HPP
