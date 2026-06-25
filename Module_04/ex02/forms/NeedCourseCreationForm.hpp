#ifndef NEEDCOURSECREATIONFORM_HPP
# define NEEDCOURSECREATIONFORM_HPP

# include <iostream>
# include "Form.hpp"

class NeedCourseCreationForm : public Form
{
private:
    // Add member variables here

public:
	/*Member functions*/
    void execute();

	/*Getters and Setters*/

	/*Constructors*/
    NeedCourseCreationForm(FormType type, time_t expirationDate);

	// /*Destructors*/
    ~NeedCourseCreationForm( void );

	// /*Overload operators*/
};

std::ostream& operator<<(std::ostream &output_stream, NeedCourseCreationForm& src);

#endif // NEEDCOURSECREATIONFORM_HPP
