#ifndef COURSEFINISHEDFORM_HPP
# define COURSEFINISHEDFORM_HPP

# include <iostream>
# include "Form.hpp"
class CourseFinishedForm : public Form
{
private:
    
public:
	/*Member functions*/
    void execute();

	/*Getters and Setters*/

	/*Constructors*/
    CourseFinishedForm(FormType type);

	/*Destructors*/
    ~CourseFinishedForm( void );

	/*Overload operators*/
};

std::ostream& operator<<(std::ostream &output_stream, CourseFinishedForm& src);

#endif // COURSEFINISHEDFORM_HPP
