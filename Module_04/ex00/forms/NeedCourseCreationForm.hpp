#ifndef NEEDCOURSECREATIONFORM_HPP
# define NEEDCOURSECREATIONFORM_HPP

# include <iostream>

class NeedCourseCreationForm : public Form
private:
    // Add member variables here

public:
	/*Member functions*/
    void execute();

	/*Getters and Setters*/

	/*Constructors*/
    // NeedCourseCreationForm(/*Parameterized Constructor*/);
	// NeedCourseCreationForm(void);

	// /*Destructors*/
    // ~NeedCourseCreationForm( void );

	// /*Overload operators*/
	NeedCourseCreationForm &operator=(const NeedCourseCreationForm& src);
};

// std::ostream& operator<<(std::ostream &output_stream, NeedCourseCreationForm& src);

#endif // NEEDCOURSECREATIONFORM_HPP
