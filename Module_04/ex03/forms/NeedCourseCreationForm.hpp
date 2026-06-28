#ifndef NEEDCOURSECREATIONFORM_HPP
# define NEEDCOURSECREATIONFORM_HPP

# include <iostream>
# include "Form.hpp"
# include "../objects/Course.hpp"
# include "../people/Headmaster.hpp"


class NeedCourseCreationForm : public Form
{
private:
    std::string	courseName;
	int			classesToGraduate;
	int			maxNumberOfStudents;

public:
	/*Member functions*/
    void execute(Headmaster *hm);

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
